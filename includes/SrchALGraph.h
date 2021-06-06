#pragma once
#include "AdjListGraph.h"
#include "CircularQueue.h"

class SrchALGraph : public AdjListGraph{
    protected:
        bool visited[MAX_VTXS];
            
    public:
        void resetVisited(){
            for(int i = 0; i < size; i++){
                visited[i] = false;
            }
        }
        bool isLinked(int u, int v) {
            for(Node *p = adj[u]; p != nullptr ; p = p->getLink()){
                if(p->getId() == v){ return true; }
            }
            return false;
        }

        // 깊이 우선 탐색
        void DFS(int v) {
            visited[v] = true;
            std::cout << getVertex(v) << " ";
            for(Node *p = adj[v]; p != nullptr ; p = p->getLink()){
                if(visited[p->getId()] == false){
                    DFS(p->getId());
                }
            }
        }

        // 너비 우선 탐색
        void BFS(int v) {
            visited[v] = true;
            std::cout << getVertex(v) << " ";
            CircularQueue que;
            que.enqueue(v);
            while(!que.isEmpty()){
                int v = que.dequeue();
                for(Node *w = adj[v]; w != nullptr; w = w->getLink()){
                    int id = w->getId();
                    if(!visited[id]){
                        visited[id] = true;
                        std::cout << getVertex(id) << " ";
                        que.enqueue(id);
                    }
                }
            }
        }
};


