#include "includes/RandomWalkerAdjMatGraph.h"
#include "includes/RandomWalkerWGraph.h"
#include <iostream>
#include <sstream>

int main() {
    float targetVertexPageRank;

    RandomWalkerAdjMatGraph randAdjMatGraph;
    RandomWalkerWGraph randWGraph;

    // experiement 1st
    // randAdjMatGraph.load("./data/graph.txt");
    // int a = 10;
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

    // experiment 2nd
    // randWGraph.load("./data/wGraph.txt");
    // randWGraph.display();
    // int a = 10;
    // while (a < 1000000) {
    //     std::cout << "trial: " << a << "\n";
    //     for (int i = 0; i < randWGraph.getSize(); i++) {
    //         std::cout << "Target vertex: " << randWGraph.getVertex(i) << "\n";
    //         targetVertexPageRank = randWGraph.pageRank(i, i, a, 0.2);
    //         std::cout.precision(10);
    //         std::cout << std::fixed << "Target vertex page rank: " << targetVertexPageRank << std::endl;
    //     }
    //     a *= 10;
    // }

    // experiment 3rd
    // for (int i = 1; i < 8; i++) {
    //     std::stringstream ss;
    //     ss << "./data/starwars/starwars-episode-" << i << "-interactions-allCharacters-links.tsv";
    //     std::string s = ss.str();
    //     randWGraph.loadtsv(s);
    //     targetVertexPageRank = randWGraph.pageRank(0, 0, 10000, 0.2);
    //     std::cout << std::fixed << "Target vertex page rank: " << targetVertexPageRank << std::endl;
    // }

    // experiment 4th
    // randWGraph.loadtsv("./data/starwars/starwars-full-interactions-allCharacters-links.tsv");
    // for (int i = 0; i < randWGraph.getSize(); i++) {
    //     std::cout << "Target vertex: " << randWGraph.getVertex(i) << "\n";
    //     targetVertexPageRank = randWGraph.pageRank(i, i, 1000, 0.2);
    //     std::cout.precision(10);
    //     std::cout << std::fixed << "Target vertex page rank: " << targetVertexPageRank << std::endl;
    // }

    // experiment 5rd
    // for (int i = 1; i < 8; i++) {
    //     std::stringstream ss;
    //     ss << "./data/starwars/starwars-episode-" << i << "-interactions-allCharacters-links.tsv";
    //     std::string s = ss.str();
    //     randAdjMatGraph.loadtsv(s);
    //     targetVertexPageRank = randAdjMatGraph.pageRank(0, 0, 10000, 0.2);
    //     std::cout << std::fixed << "Target vertex page rank: " << targetVertexPageRank << std::endl;
    // }

    // experiment 6th
    // randAdjMatGraph.loadtsv("./data/starwars/starwars-full-interactions-allCharacters-links.tsv");
    // for (int i = 0; i < randAdjMatGraph.getSize(); i++) {
    //     std::cout << "Target vertex: " << randAdjMatGraph.getVertex(i) << "\n";
    //     targetVertexPageRank = randAdjMatGraph.pageRank(i, i, 1000, 0.2);
    //     std::cout.precision(10);
    //     std::cout << std::fixed << "Target vertex page rank: " << targetVertexPageRank << std::endl;
    // }

    // experiment 7th
    // randWGraph.loadtsv("./data/bicycle/bicycle_trips_over_50.tsv");
    // targetVertexPageRank = randWGraph.pageRank(0, 0, 10000, 0.2);
    // std::cout << std::fixed << "Target vertex page rank: " << targetVertexPageRank << std::endl;

    // experiment 8th
    randWGraph.loadtsv("./data/bicycle/bicycle_trips_over_50.tsv");
    for (int i = 0; i < randWGraph.getSize(); i++) {
        std::cout << "Target vertex: " << randWGraph.getVertex(i) << "\n";
        targetVertexPageRank = randWGraph.pageRank(i, i, 10000, 0.2);
        std::cout.precision(10);
        std::cout << std::fixed << "Target vertex page rank: " << targetVertexPageRank << std::endl;
    }

    return 0;
}