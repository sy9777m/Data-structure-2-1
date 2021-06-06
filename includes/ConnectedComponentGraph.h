#pragma once
#include <iostream>
#include "SrchAMGraph.h"

class ConnectedComponentGraph : public SrchAMGraph{
    protected:
        int	label[MAX_VTXS];

    public:
        void labelDFS(int v, int color) {
            visited[v] = true;				
            label[v] = color;				
            std::cout << getVertex(v) << " ";
            for(int w = 0; w < size; w++){ 
                if(isLinked(v, w) && visited[w]==false){
                    labelDFS(w, color);
                }
            }
        }
        void findConnectedComponent(){
            int count = 0;					
            for(int i = 0; i < size; i++){
                if( visited[i]==false){    
                    labelDFS(i, ++count);
                }
            }
            std::cout << "\nNumber of Connected Components: " << count << "\n";
            for(int i = 0; i < size; i++){
                std::cout << getVertex(i) << ":" << label[i] << " ";
            }
            std::cout << "\n";
        }
};

