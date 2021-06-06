#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include "AdjMatGraph.h"

#define INF 9999

class WGraph : public AdjMatGraph{
    public:
        WGraph(){}
        ~WGraph(){}

        bool hasEdge(int i, int j){ return (getEdge(i,j) < INF); }

        void insertEdge(int u, int v, int weight){
            if(weight >= INF){ weight = INF; }
            setEdge(u, v, weight);
        }

        void load(std::string filename){
            // std::cout << filename << std::endl;
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
                    insertEdge(i, j, val);
                }
            }
            ifs.close();
        }
};
