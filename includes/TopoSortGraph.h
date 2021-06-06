#pragma once
#include "AdjListGraph.h"
#include "ArrayStack.h"

class TopoSortGraph : public AdjListGraph{
    public:
        TopoSortGraph(void){}
        ~TopoSortGraph(void){}

        void insertDirEdge( int u, int v ) { // u->v의 방향성 있는 edge를 만듭니다
            adj[u] = new Node (v, adj[u]);	//
        }
        void TopoSort(){
            ArrayStack s;

            int *inDeg = new int [size]; // 모든 정점의 in-degree를 구합니다

            for(int i = 0; i < size; i++){ // indegree 초기화
                inDeg[i] = 0;
            }

            for(int i = 0; i < size; i++){
                Node *node = adj[i];
                while(node != NULL){
                    inDeg[node->getId()]++;
                    node = node->getLink();
                }
            }
            for(int i = 0; i < size; i++){
                if(inDeg[i] == 0){ s.push(i); }
            } // indegree가 0인 vertex들을 stack에 삽입합니다.
            // 이 vertex들이 위상정렬에서 처음 나오는 vertex 들입니다.
            
            while(s.isEmpty() == false){
                int w = s.pop();
                std::cout << getVertex(w) << " ";
                Node *node = adj[w];
                while(node != nullptr){
                    int u = node->getId(); // seed vertex의 이웃 vertex에 대해 연산을 수행합니다
                    inDeg[u]--;	// 그 노드들의 in-degree를 하나씩 줄여줍니다
                    if(inDeg[u] == 0)
                        s.push(u); // in-degree가 0이 되면 그 노드를 다시 stack으로 넣어줍니다
                    node = node->getLink();	// 다음 이웃을 조회합니다
                }
            }
            std::cout << "\n";
            delete [] inDeg; // array 삭제는 delete [] 인것 잊지 마세요
        }
};

