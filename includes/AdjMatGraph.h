#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#define MAX_VTXS 10000

class AdjMatGraph{
    protected:
        int size;
        std::string *vertices = new std::string[MAX_VTXS];
        int **adj = new int*[MAX_VTXS];

    public:
        AdjMatGraph(){
            for (int i = 0; i < MAX_VTXS; ++i) {
                adj[i] = new int[MAX_VTXS];
            }
            reset();
        }

        ~AdjMatGraph(){
            delete [] adj, vertices;
        }

        std::string getVertex(int i){ return vertices[i]; }
        int getEdge(int i, int j) { return adj[i][j]; }

        void setEdge(int i, int j, int val) { adj[i][j] = val; }

        bool isEmpty(){ return size==0; }
        bool isFull(){ return size>=MAX_VTXS; }

        void reset(){
            size=0;
            for(int i=0 ; i<MAX_VTXS ; i++){
                for(int j=0 ; j<MAX_VTXS ; j++){
                    setEdge(i,j,0);
                }
            }
        }

        void insertVertex(std::string name){
            if(!isFull()){ vertices[size++] = name; }
            else { std::cout << "Exceeding maximum number of vertices"; } 
        }

        void insertEdge(int u, int v){
            setEdge(u, v, 1);
            setEdge(v, u, 1);
        }

        void display(){
            std::cout << size << "\n";
            for(int i=0 ; i<size ; i++){
                std::cout << getVertex(i) << "  ";
                for(int j=0 ; j<size ; j++)  
                    std::cout << getEdge(i, j) << " ";
                std::cout << "\n";
            }
        }

        void load(std::string filename){
            std::ifstream ifs(filename);
            std::string line;
            std::getline(ifs, line);
            // std::cout << line << std::endl;
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

        void store(std::string filename) {
            std::ofstream ofs(filename);
            ofs << size << "\n";
            for(int i = 0 ; i < size ; i++){
                ofs << getVertex(i) << "  ";
                for(int j = 0 ; j < size ; j++)  
                    ofs << getEdge(i, j) << " ";
                ofs << "\n";
            }
            ofs.close();
        }
    };




