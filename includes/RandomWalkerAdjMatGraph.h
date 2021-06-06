#include "AdjMatGraph.h"
#include <iostream>
#include <random>

class RandomWalkerAdjMatGraph : public AdjMatGraph {
    public:
        int randomWalker(int startIndex, int trial, float jumpProb) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<float> indexDis(0, size);
            std::uniform_real_distribution<float> realDis(0, 1);

            int finalIndex = startIndex;

            // trial 수 만큼 loop
            for (int i = 0; i < trial; i++) {
                // jump 여부를 결정할 난수를 생성
                float jump = realDis(gen);

                // jump
                if (jump < jumpProb) {
                    // std::cout << "jump" << "\n";

                    // random으로 이동할 임의의 vertex 선택
                    finalIndex = static_cast<int>(indexDis(gen));

                    // size와 같은 index가 생성됐을 경우, crash 방지
                    if (finalIndex == size) {
                        finalIndex -= 1;
                    }
                    
                    // std::cout << "final index: " << finalIndex << "\n";
                    // std::cout << "jump to Vertex " << getVertex(finalIndex) << "\n";
                }
                // jump 안 함
                else {
                    // std::cout << "not jump" << "\n";

                    // linked된 vertex의 index를 저장하기 위한 array
                    int *linkedList = new int[MAX_VTXS];
                    // linked된 vertex의 개수를 세기 위한 linked variable
                    int linked = 0;
                    
                    // linked 여부 체크
                    for (int j = 0; j < size; j++) {
                        if(isLinked(finalIndex, j)) {
                            // linked된 vertex의 index가 linkedList에 순서대로 저장됨
                            linkedList[linked++] = j;
                        }
                    }

                    // random으로 index 생성
                    // linked value보다 1 작아야 함 because 상단과 하단을 포함하여 난수를 생성하기 때문
                    std::uniform_int_distribution<int> indexDis(0, linked-1);

                    // 생성한 난수로 이동할 vertex의 index를 fianlIndex에 저장
                    finalIndex = linkedList[indexDis(gen)];
                    
                    // std::cout << "final index: " << finalIndex << "\n";
                    // std::cout << "move to Vertex " << getVertex(finalIndex) << "\n";

                    delete [] linkedList;
                }
            }

            // 최종적으로 fianlIndex를 반환
            return finalIndex;
        }

        float pageRank(int startIndex, int targetIndex, int trial, float jumpProb) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<float> indexDis(0, size);
            std::uniform_real_distribution<float> realDis(0, 1);

            // page 방문 횟수를 담는 array
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
                    // 방문할 때마다 value를 올려줌
                    pageRankList[finalIndex]++;
                }
                else {
                    int *linkedList = new int[MAX_VTXS];
                    int linked = 0;

                    for (int j = 0; j < size; j++) {
                        if(isLinked(finalIndex, j)) {
                            linkedList[linked++] = j;
                        }
                    }
                    std::uniform_int_distribution<int> indexDis(0, linked-1);

                    finalIndex = linkedList[indexDis(gen)];
                    // 방문할 때마다 value를 올려줌
                    pageRankList[finalIndex]++;

                    delete [] linkedList;
                }
            }

            for (int i = 0; i < size; i++) {
                std::cout << "[" << pageRankList[i] << "] ";
            }

            std::cout << "\n";
            // pageRank 계산
            float targetPageRank = static_cast<float>(pageRankList[targetIndex]) / static_cast<float>(trial);

            delete [] pageRankList;

            return targetPageRank;
        }

        bool isLinked(int u, int v){ return getEdge(u,v) != 0; }

        int getSize() { return size; }
};