#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <vector>
#include <sstream>
#include "Graph.hpp"
#include <string>
#include <algorithm> // Add this line
#include <queue>
#include <iostream>
#include <stack>
namespace ariel
{
    class Algorithms
    {
    public:
        static bool isConnected(const Graph &g);
        static std::string shortestPath(const Graph &g, int start, int end);
        static std::string isContainsCycle(const Graph &g);
        static  std::string negativeCycle(const Graph &g); // Added method declaration
                static std::string isBipartite(const Graph &g); // Added method declaration


    private:
        static bool hasCycleHelper(const Graph& g, int v, std::vector<bool>& visited, int parent, std::vector<int>& cycle);
    };
}

#endif
