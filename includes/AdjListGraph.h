#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#define MAX_VTXS 256

class Node{
    protected:
        int id;  // Vertex의 id
        Node* link; // 이웃 노드의 포인터
    public:
        Node(int i, Node *l=NULL) : id(i), link(l) { }
        ~Node(void) { 
			delete link;
        }
        int   getId()   { return id; }
        Node* getLink()   { return link; }
        void setLink(Node* l) { link = l; }
};

class AdjListGraph{
    protected:
        int  size; // Vertex의 총 수 
        std::string vertices[MAX_VTXS]; // Vertex의 정보 (Node 등으로 확장이 가능합니다)
        Node* adj[MAX_VTXS];  // 각 Vertex의 인접 리스트

    public:
        AdjListGraph(void): size(0) {}
        ~AdjListGraph(void){ reset(); }

        void reset(void){ 
            for(int i = 0; i < size; i++){
                delete adj[i];
            }
            size = 0;
        }
        bool isEmpty(){ return size == 0; }
        bool isFull(){ return size >= MAX_VTXS; }
        std::string getVertex(int i){ return vertices[i]; }

        void insertVertex(std::string val){
            if(!isFull()){
                vertices[size] = val;
                adj[size++] = nullptr;
            }
            else { std::cout << "Exceeding maximum number of vertices"; } 
        }

        void insertEdge(int u, int v){
            //adj[u] = new Node(v, adj[u]);
            //만약 Adj Matrix와같은 순서로 만들고 싶으면
            if(adj[u] == nullptr){
                adj[u] = new Node(v, adj[u]);
            }
            else{
                Node *p = adj[u];
                while(p->getLink() != nullptr){
                    p = p->getLink();
                }
                p->setLink(new Node(v, nullptr));
            }
            //adj[v] = new Node(u, adj[v]);
        }

        void display(){
            std::cout << size << "\n";
            for(int i = 0; i < size; i++){
                std::cout << getVertex(i) << "  ";
                for(Node *v = adj[i]; v != nullptr; v = v->getLink()){
                    std::cout << getVertex(v->getId()) << " ";
                }
                std::cout << "\n";
            }            
        }

        void load(std::string filename){
            std::ifstream ifs(filename);
            std::string line;
            std::getline(ifs, line);
            std::cout << line << std::endl;
            std::stringstream ls(line);
            int n;
            ls >> n;
            for(int i = 0; i < n; i++){
                std::getline(ifs, line);
                std::string str;
                int val;
                std::stringstream ls(line);
                ls >> str;
                insertVertex(str);
                for(int j = 0; j < n; j++){
                    ls >> val;
                    if(val != 0){
                        insertEdge(i, j);
                    }
                }
            }
            ifs.close();
        }

};

