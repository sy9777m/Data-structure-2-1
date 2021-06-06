#include "includes/RandomWalkerAdjMatGraph.h"
#include "includes/RandomWalkerWGraph.h"
#include <iostream>

int main() {
    // RandomWalkerAdjMatGraph randAdjMatGraph;

    // experiement 1st
    // randAdjMatGraph.load("./data/graph.txt");
    // int a = 10;
    // float targetVertexPageRank;
    // while (a < 10000000) {
    //     std::cout << "trial: " << a << "\n";
    //     for (int i = 0; i < randAdjMatGraph.getSize(); i++) {
    //         std::cout << "Target vertex: " << randAdjMatGraph.getVertex(i) << "\n";
    //         targetVertexPageRank = randAdjMatGraph.pageRank(i, i, a, 0.2);
    //         std::cout.precision(10);
    //         std::cout << std::fixed << "Target vertex page rank: " << targetVertexPageRank << std::endl;
    //     }
    //     a *= 10;
    // }

    RandomWalkerWGraph randWGraph;

    // experiment 2nd
    randWGraph.load("./data/wGraph.txt");
    int a = 10;
    float targetVertexPageRank;
    while (a < 10000000) {
        std::cout << "trial: " << a << "\n";
        for (int i = 0; i < randWGraph.getSize(); i++) {
            std::cout << "Target vertex: " << randWGraph.getVertex(i) << "\n";
            targetVertexPageRank = randWGraph.pageRank(i, i, a, 0.2);
            std::cout.precision(10);
            std::cout << std::fixed << "Target vertex page rank: " << targetVertexPageRank << std::endl;
        }
        a *= 10;
    }
    
    return 0;
}