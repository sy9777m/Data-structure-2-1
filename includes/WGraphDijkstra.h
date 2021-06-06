#pragma once

#include "WGraph.h"
#include <iostream>

class WGraphDijkstra : public WGraph{
    protected:
        int path[MAX_VTXS];
        int dist[MAX_VTXS];	
        bool found[MAX_VTXS]; // 최단거리를 찾았는지 여부 확인

    public:
        WGraphDijkstra(){}
        ~WGraphDijkstra(){}

        void PrintDistance(){
            for(int i = 0; i < size; i++){
                std::cout << dist[i] << " ";
            }
        }

        void PrintPath(int start, int end){  
            std::cout << "Shortest path " << getVertex(end) << "->" << getVertex(start) << ": ";
            std::cout << getVertex(end);
            while(path[end] != start){
                std::cout << "-" << getVertex(path[end]);
                end = path[end];
            }
            //std::cout << "-" << getVertex(path[end]) << "\n";
            std::cout << "-" << getVertex(start) << "\n";
        }

        int chooseVertex(){ 
            // 이미 subgroup에서 최단거리리를 찾은 node group에서 
            // 가장 가까운 못찾은 node를 구합니다
            int min = INF;
            int minpos = -1;
            for(int i = 0; i < size; i++){
                if(dist[i]< min && !found[i]){
                    min = dist[i];
                    minpos = i;
                }
            }
            return minpos;
        }

        void ShortestPath(int start){
            for(int i = 0; i < size; i++){
                dist[i] = getEdge(start, i);
                path[i] = start;
                found[i] = false;
            }
            found[start] = true;		
            dist[start] = 0; // 시작점까지와의 거리는 0

            for(int i = 0; i < size; i++){
                std::cout << "STEP " << i+1 << " ";
                PrintDistance();
                int u = chooseVertex(); 
                // 최단경로를 모르는 노드 중 현재 발견된 노드에서 가장 가까운 노드를 뽑습니다.
                // negative weight가 없으므로 이렇게 뽑은 경로는 당연히 최단경로가 됩니다.
                found[u] = true;
                for(int w = 0; w < size; w++){
                    if(!found[w]){
                        if(dist[u] + getEdge(u,w) < dist[w]){
                            // 만약 최단거리를 아직 모르는 w에 대햇허
                            // u를 거치는 경로가 기존에 우리가 정해준 경로보다 짧다면
                            // (INF이거나, start부터의 weight이거나 둘 중 하나일 것입니다)
                            // 최단 경로를 u를 거치는 경로로 바꿔줍니다
                            // 다시한번 강조. negative weight가 있으면 작동 안합니다.
                            dist[w] = dist[u] + getEdge(u,w);
                            path[w] = u;
                        }
                    }
                }
                std::cout << "\n";
            }
        }
};


