#pragma once

#include <iostream>

#include "OLinkedList.h"
#include "WGraph.h"
#include "VertexSets.h"

// WGraphMST: 최소 신장 트리(MST) 기능이 추가된 가중치 그래프 클래스
class WGraphMST : public WGraph{
    public:
        // kruskal의 최소 비용 신장 트리 프로그램
        void Kruskal(){
            o_linked_list o_edgelist;
            for(int i = 0; i < size - 1; i++){
                for(int j = i+1; j < size; j++){
                    if(hasEdge(i,j)) {
                        o_edgelist.orderedInsert(new node(getEdge(i,j), i, j));
                    }
                }
            }
            VertexSets set(size);					
            int	edgeAccepted=0;						
            while(edgeAccepted < size-1){			
                node* e = o_edgelist.getHead();
                int uset = set.findSet(e->getSource());
                int vset = set.findSet(e->getTarget());	
                if(uset != vset){
                    std::cout << "An edge added to MST: " << getVertex(e->getSource());
                    std::cout << " " << getVertex(e->getTarget()) << " " << e->getWeight() << "\n";
                    set.unionSets(uset, vset);
                    edgeAccepted++;
                }
                o_edgelist.removeHead();

            }
        }

        // Prim의 최소 비용 신장 트리 프로그램
        void Prim(){
            bool selected[MAX_VTXS];		
            int dist[MAX_VTXS];
            int source_vertex[MAX_VTXS];
            for(int i = 0; i < size; i++){
                dist[i] = INF;
                selected[i] = false;
                source_vertex[i] = 0;
            }

            dist[0]=0;

            for(int i = 0; i < size; i++){
                int u = getMinVertex(selected, dist);
                //현재 MST에서 최소 거리 vertex를 고릅니다
                selected[u] = true;
                if(dist[u] >= INF){
                    return;
                }
                if(u != source_vertex[u]){
                    std::cout << "An edge added to MST: " << getVertex(u) << " ";
                    std::cout << getVertex(source_vertex[u]) << " " << getEdge(u, source_vertex[u])<< "\n";
                }
                for(int v = 0; v < size; v++){ // 새 MST부터 노드들의 거리를 업데이트해 줍니다
                    if(getEdge(u,v) != INF){
                        if(!selected[v] && getEdge(u, v) < dist[v]){
                            dist[v] = getEdge(u, v);
                            source_vertex[v] = u;
                        }
                    }
                }
            }
            std::cout << "\n";
        }

        int getMinVertex(bool* selected, int* dist) {
            int minv = 0;
            int mindist	= INF;
            for(int v = 0; v<size; v++){
                if(!selected[v] && dist[v]<mindist){
                    mindist = dist[v];
                    minv = v;
                }
            }
            return minv;
        }
};
