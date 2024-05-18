#include "Algorithms.hpp"
#include <vector>
#include <climits>

namespace ariel {
    std::string Algorithms::isBipartite(const Graph &g) {
        int numVertices = g.getNumVertices();
        std::vector<int> color(numVertices, -1); // -1 indicates uncolored

        // Use BFS to attempt to color the graph
        for (int start = 0; start < numVertices; ++start) {
            if (color[start] == -1) { // If the vertex is uncolored
                std::queue<int> q;
                q.push(start);
                color[start] = 0; // Start coloring with 0

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    // Get all adjacent vertices
                    const std::vector<std::vector<int>>& adjacencyMatrix = g.getAdjacencyMatrix();
                    for (int v = 0; v < numVertices; ++v) {
                        if (adjacencyMatrix[u][v] != 0) { // There's an edge
                            if (color[v] == -1) { // If uncolored, color with opposite color
                                color[v] = 1 - color[u];
                                q.push(v);
                            } else if (color[v] == color[u]) { // If colored the same as adjacent
                                return "The graph is not bipartite.";
                            }
                        }
                    }
                }
            }
        }

        // If bipartite, organize vertices into sets A and B
        std::vector<int> setA;
        std::vector<int> setB;
        for (int i = 0; i < numVertices; ++i) {
            if (color[i] == 0) {
                setA.push_back(i);
            } else if (color[i] == 1) {
                setB.push_back(i);
            }
        }

        // Format the output to show two sets
        std::stringstream ss;
        ss << "The graph is bipartite: A={";
        for (size_t i = 0; i < setA.size(); ++i) {
            ss << setA[i];
            if (i < setA.size() - 1) ss << ", ";
        }
        ss << "}, B={";
        for (size_t i = 0; i < setB.size(); ++i) {
            ss << setB[i];
            if (i < setB.size() - 1) ss << ", ";
        }
        ss << "}.";
        return ss.str();
    }
    
    
    
    
    
    
    bool Algorithms::isConnected(const Graph& g) {
    int numVertices = g.getNumVertices();
    const std::vector<std::vector<int>>& adjMatrix = g.getAdjacencyMatrix();

    std::vector<bool> visited(numVertices, false);
    
    // Find a vertex with non-zero out-degree to start DFS
    for (int start = 0; start < numVertices; ++start) {
        std::fill(visited.begin(), visited.end(), false);
        int outDegree = 0;
        for (int i = 0; i < numVertices; ++i) {
            if (adjMatrix[start][i] != 0) {
                outDegree++;
            }
        }
        if (outDegree == 0) continue;  // Skip if no outgoing edges
        
        // Simple DFS
        std::stack<int> stack;
        stack.push(start);
        visited[start] = true;
        int count = 1;

        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();

            for (int adj = 0; adj < numVertices; ++adj) {
                if (adjMatrix[node][adj] != 0 && !visited[adj]) {
                    visited[adj] = true;
                    stack.push(adj);
                    count++;
                }
            }
        }
        
        if (count == numVertices) return true;  // Found a node from which all nodes are reachable
    }

    return false;  // No such starting node found
}

     
std::string Algorithms::shortestPath(const Graph& g, int start, int end) {
    int numVertices = g.getNumVertices();
    const std::vector<std::vector<int>>& adjacencyMatrix = g.getAdjacencyMatrix();

    // Initialize distances and parent arrays
    std::vector<int> distances(numVertices, INT_MAX);
    std::vector<int> parents(numVertices, -1);
    distances[start] = 0;

    // Relax edges repeatedly
    for (int i = 1; i < numVertices; ++i) {
        for (int u = 0; u < numVertices; ++u) {
            for (int v = 0; v < numVertices; ++v) {
                if (adjacencyMatrix[u][v] > 0 && distances[u] != INT_MAX && 
                    distances[u] + adjacencyMatrix[u][v] < distances[v]) {
                    distances[v] = distances[u] + adjacencyMatrix[u][v];
                    parents[v] = u;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < numVertices; ++u) {
        for (int v = 0; v < numVertices; ++v) {
            if (adjacencyMatrix[u][v] > 0 && distances[u] != INT_MAX && 
                distances[u] + adjacencyMatrix[u][v] < distances[v]) {
                return "Graph contains a negative weight cycle";
            }
        }
    }

    // If no path exists
    if (distances[end] == INT_MAX) {
        return "-1";
    }

    // Reconstruct the shortest path
    std::vector<int> path;
    int at = end;
 while (at != -1) {
    path.push_back(at);
    if (at == start) break;  // Stop if we've reached the start
    at = parents[at];
}

    
    if (path.back() != start) { // Check if the path is valid
        return "No path exists";
    }
    
    std::reverse(path.begin(), path.end());

    // Convert path to string representation
    std::stringstream ss;
    for (size_t i = 0; i < path.size(); ++i) {
        ss << path[i];
        if (i < path.size() - 1) {
            ss << "->";
        }
    }

    return ss.str();
}

bool Algorithms::hasCycleHelper(const Graph& g, int v, std::vector<bool>& visited, int parent, std::vector<int>& cycle) {
    visited[v] = true;
    cycle.push_back(v);  // Add current vertex to the cycle

    const std::vector<std::vector<int>>& adjacencyMatrix = g.getAdjacencyMatrix();
    int numVertices = adjacencyMatrix.size();

    for (int u = 0; u < numVertices; ++u) {
        if (adjacencyMatrix[v][u] != 0) { // There is an edge from v to u
            if (!visited[u]) { // If u has not been visited, recurse
                if (hasCycleHelper(g, u, visited, v, cycle)) {
                    
                    return true;
                }
            } else if (u != parent) { // u is visited and not the parent, cycle detected
                // Avoid adding 'u' again, just return true to indicate cycle is complete
                return true;
            }
        }
    }

    cycle.pop_back(); // No cycle found with v as a start point, backtrack
    return false;
}

std::string Algorithms::isContainsCycle(const Graph &g) {
    int numVertices = g.getNumVertices();
    std::vector<bool> visited(numVertices, false);
    std::vector<int> cycle;

    for (int v = 0; v < numVertices; ++v) {
        if (!visited[v]) {
            if (hasCycleHelper(g, v, visited, -1, cycle)) {
                std::cerr << "Cycle detected: ";
    for (int node : cycle) std::cerr << node << " ";
    std::cerr << std::endl;
                // Cycle found, format it into a string
                std::stringstream ss;
                for (size_t i = 0; i < cycle.size(); ++i) {
                    ss << cycle[i];
                    if (i < cycle.size() - 1) {
                        ss << "->";
                    }
                }
                ss << "->" << cycle[0]; // Complete the cycle by connecting back to the start
                return ss.str();
            }
        }
    }

    return "0"; // If no cycle is found
}


  static bool bellmanFord(const Graph& g, int src, std::vector<int>& parent, std::vector<int>& dist) {
        int numVertices = g.getNumVertices();
        dist.assign(numVertices, INT_MAX);
        dist[src] = 0;
        parent.assign(numVertices, -1);

        const std::vector<std::vector<int>>& adjacencyMatrix = g.getAdjacencyMatrix();

        // Relax all edges |V| - 1 times
        for (int i = 0; i < numVertices - 1; ++i) {
            for (int u = 0; u < numVertices; ++u) {
                for (int v = 0; v < numVertices; ++v) {
                    if (adjacencyMatrix[u][v] != 0 && dist[u] != INT_MAX &&
                        dist[u] + adjacencyMatrix[u][v] < dist[v]) {
                        dist[v] = dist[u] + adjacencyMatrix[u][v];
                        parent[v] = u;
                    }
                }
            }
        }

        // Check for negative-weight cycles
        for (int u = 0; u < numVertices; ++u) {
            for (int v = 0; v < numVertices; ++v) {
                if (adjacencyMatrix[u][v] != 0 && dist[u] != INT_MAX &&
                    dist[u] + adjacencyMatrix[u][v] < dist[v]) {
                    return true; // Negative cycle found
                }
            }
        }

        return false;
    }

    std::string Algorithms::negativeCycle(const Graph &g) {
        int numVertices = g.getNumVertices();
        std::vector<int> parent(numVertices);
        std::vector<int> dist(numVertices);

        for (int src = 0; src < numVertices; ++src) {
            if (bellmanFord(g, src, parent, dist)) {
                // Find a vertex part of the cycle
                int v = src;
                for (int i = 0; i < numVertices; ++i) { // Move far enough in the cycle
                    v = parent[v];
                }

                // Locate the start of the cycle
                std::vector<int> cycle;
                int start = v;
                do {
                    cycle.push_back(v);
                    v = parent[v];
                } while (v != start);

                cycle.push_back(start); // Close the cycle
                std::reverse(cycle.begin(), cycle.end());
                
                // Convert cycle to string
                std::stringstream ss;
                for (size_t i = 0; i < cycle.size(); ++i) {
                    ss << cycle[i];
                    if (i < cycle.size() - 1) {
                        ss << "->";
                    }
                }
                return ss.str();
            }
        }

        return "0"; // No negative cycle found
    }
    
    }
