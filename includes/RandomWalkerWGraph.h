#include <time.h>
#include <algorithm>
#include "wGraph.h"
#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <fstream>
#include <sstream>

class RandomWalkerWGraph : public WGraph {
    public:
        int randomWalker(int startIndex, int trial, float jumpProb) {
            std::random_device rd;
            std::mt19937 gen = std::mt19937((unsigned int)time(NULL));
            std::uniform_real_distribution<float> indexDis(0, size);
            std::uniform_real_distribution<float> realDis(0, 1);

            int finalIndex = startIndex;

            for (int i = 0; i < trial; i++) {
                float jump = realDis(gen);

                if (jump < jumpProb) {
                    // std::cout << "jump" << "\n";

                    finalIndex = static_cast<int>(indexDis(gen));

                    if (finalIndex == size) {
                        finalIndex -= 1;
                    }
                    
                    // std::cout << "final index: " << finalIndex << "\n";
                    // std::cout << "jump to Vertex " << getVertex(finalIndex) << "\n";
                }
                else {
                    // std::cout << "not jump" << "\n";

                    int *linkedList = new int[MAX_VTXS];
                    int linked = 0;
                    // weight 누적합을 담는 array
                    // linked된 vertex의 index는 위 linkedList에 저장되고
                    // linkedList에 저장된 index와 동일한 index에 weight의 누적 합을 저장
                    int *weightList = new int[MAX_VTXS];
                    
                    for (int j = 0; j < size; j++) {
                        if(hasEdge(finalIndex, j)) {
                            // 자기 자신으로 move하는 가능성을 제거하기 위한 if statement
                            if(getEdge(finalIndex, j) == 0) {
                                continue;
                            }

                            linkedList[linked] = j;
                            // 최초 linked vertex를 발견했을 경우는 weight의 누적합을 저장하는 것이 아닌 해당 값을 저장
                            if (linked == 0) {
                                weightList[linked++] = getEdge(finalIndex, j);
                            }
                            // 2번째 발견한 linked vertex부터 weight의 누적합을 저장
                            else {
                                weightList[linked] = getEdge(finalIndex, j) + weightList[linked-1];
                                linked++;
                            }
                            
                        }
                    }

                    // std::cout << "linked list: ";
                    // for (int j = 0; j < linked; j++) {
                    //     std::cout << "[" << linkedList[j] << "] ";
                    // }
                    // std::cout << "\n";

                    // std::cout << "weight list: ";
                    // for (int j = 0; j < linked; j++) {
                    //     std::cout << "[" << weightList[j] << "] ";
                    // }
                    // std::cout << "\n";
                    
                    // 0 ~ 누적합 사이에서 난수 생성
                    std::uniform_int_distribution<int> weightDis(0, weightList[linked-1]);
                    int randomWeight = weightDis(gen);

                    for (int k = 0; k < linked; k++) {
                        // 첫 루프가 돌 때는 가장 작은 누적합과 random으로 생성된 누적합을 비교하므로
                        // random 누적합이 비교대상 누적합보다 작으면 해당 index의 vertex로 이동
                        if (k == 0 && randomWeight < weightList[k]) {
                            finalIndex = linkedList[k];
                        }
                        // 두 번째 루프부터는 random으로 생성된 누적합이 비교대상 누적합보다 작고, 비교대상 누적합의 전 누적합보다 크거나 같으면
                        // 해당 index의 vertex로 이동
                        else if (randomWeight < weightList[k] && randomWeight >= weightList[k-1]) {
                            finalIndex = linkedList[k];
                        }
                    }
                    
                    // std::cout << "final index: " << finalIndex << "\n";
                    // std::cout << "move to Vertex " << getVertex(finalIndex) << "\n";

                    delete [] linkedList;
                }
            }

            return finalIndex;
        }

        float pageRank(int startIndex, int targetIndex, int trial, float jumpProb) {
            std::random_device rd;
            std::mt19937 gen = std::mt19937((unsigned int)time(NULL));
            std::uniform_real_distribution<float> indexDis(0, size);
            std::uniform_real_distribution<float> realDis(0, 1);

            int *pageRankList = new int[MAX_VTXS];
            for (int i = 0; i < size; i++) {
                pageRankList[i] = 0;
            }

            for (int i = 0; i < trial; i++) {
                int finalIndex = startIndex;
                float jump = realDis(gen);

                if (jump < jumpProb) {
                    finalIndex = static_cast<int>(indexDis(gen));
                    if (finalIndex == size) {
                        finalIndex -= 1;
                    }
                    pageRankList[finalIndex]++;
                }
                else {
                    int *linkedList = new int[MAX_VTXS];
                    int linked = 0;
                    int *weightList = new int[MAX_VTXS];

                    for (int j = 0; j < size; j++) {
                        if(hasEdge(finalIndex, j)) {
                            if(getEdge(finalIndex, j) == 0) {
                                continue;
                            }

                            linkedList[linked] = j;
                            if (linked == 0) {
                                weightList[linked++] = getEdge(finalIndex, j);
                            }
                            else {
                                weightList[linked] = getEdge(finalIndex, j) + weightList[linked-1];
                                linked++;
                            }
                        }
                    }

                    std::uniform_int_distribution<int> weightDis(0, weightList[linked-1]);
                    int randomWeight = weightDis(gen);

                    for (int k = 0; k < linked; k++) {
                        if (k == 0 && randomWeight < weightList[k]) {
                            finalIndex = linkedList[k];
                        }
                        else if (randomWeight < weightList[k] && randomWeight >= weightList[k-1]) {
                            finalIndex = linkedList[k];
                        }
                    }

                    pageRankList[finalIndex]++;

                    delete [] linkedList, weightList;
                }
            }

            for (int i = 0; i < size; i++) {
                std::cout << "[" << pageRankList[i] << "] ";
            }

            std::cout << "\n";

            float targetPageRank = static_cast<float>(pageRankList[targetIndex]) / static_cast<float>(trial);

            delete [] pageRankList;

            return targetPageRank;
        }

        bool isLinked(int u, int v){ return getEdge(u,v) != 0; }

        int getSize() { return size; }

        void loadtsv(std::string filename) {
            std::ifstream ifs(filename);
            std::string line;
            std::getline(ifs, line);
            
            int *source = new int[MAX_VTXS];
            int *target = new int[MAX_VTXS];
            int *weight = new int[MAX_VTXS];
            int length = 0;

            while (getline(ifs, line)) {
                std::stringstream ss(line);
                std::vector<std::string> item;
                std::string tmp;
                int i = 1;    
                int num;

                while(getline(ss, tmp, '\t')) {
                    if (i == 1) {
                        std::stringstream ssInt(tmp);
                        ssInt >> num;
                        source[length] = num;
                        i++;
                    }
                    else if (i == 2) {
                        std::stringstream ssInt(tmp);
                        ssInt >> num;
                        target[length] = num;
                        i++;
                    }
                    else {
                        std::stringstream ssInt(tmp);
                        ssInt >> num;
                        weight[length++] = num;
                        i = 1;
                    }
                }
            }
            ifs.close();

            int min = source[0];
            int max = source[0];

            for (int i = 0; i < length; i++) {
                insertEdge(source[i], target[i], weight[i]);
                min = std::min(min, source[i]);
                max = std::max(max, source[i]);
                // std::cout << "source: " << source[i] << " / target: " << target[i] << " / weight: " << weight[i] << "\n";
            }

            for (min; min < max + 1; min++) {
                insertVertex(std::to_string(min));
            }

            delete [] source, target, weight;
        }
};