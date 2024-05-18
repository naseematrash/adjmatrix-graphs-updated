#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

namespace ariel {
    Graph::Graph() : numVertices(0), numEdges(0), isDirected(true) {}

    void Graph::loadGraph(const std::vector<std::vector<int>>& graph) {
        int rows = graph.size();
        int cols = graph[0].size();

        if (rows != cols) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

        adjacencyMatrix = graph;
        numVertices = rows;
        isDirected = false; // Assume undirected until proven otherwise

        // Check for symmetry and count edges
        numEdges = 0;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
                    isDirected = true; // If any asymmetric entry is found, it's a directed graph
                }
                if (adjacencyMatrix[i][j] != 0) {
                    ++numEdges;
                }
            }
        }
        if (!isDirected) {
            numEdges /= 2; // Divide by 2 for undirected graphs
        }
    }

    void Graph::printGraph() const {
        std::cout << "Graph with " << numVertices << " vertices and " << numEdges << " edges";
        if (isDirected) {
            std::cout << " (Directed)" << std::endl;
        } else {
            std::cout << " (Undirected)" << std::endl;
        }
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjacencyMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    int Graph::getNumVertices() const {
        return numVertices;
    }

    int Graph::getNumEdges() const {
        return numEdges;
    }

    const std::vector<std::vector<int>>& Graph::getAdjacencyMatrix() const {
        return adjacencyMatrix;
    }

    // Addition operator
    Graph Graph::operator+(const Graph& other) const {
        if (numVertices != other.numVertices) {
            throw std::invalid_argument("Graphs must be of the same size for addition.");
        }
        Graph result;
        result.numVertices = numVertices;
        result.isDirected = isDirected;
        result.adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                result.adjacencyMatrix[i][j] = adjacencyMatrix[i][j] + other.adjacencyMatrix[i][j];
            }
        }
        return result;
    }

    // Addition assignment operator
    Graph& Graph::operator+=(const Graph& other) {
        if (numVertices != other.numVertices) {
            throw std::invalid_argument("Graphs must be of the same size for addition.");
        }
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                adjacencyMatrix[i][j] += other.adjacencyMatrix[i][j];
            }
        }
        return *this;
    }

    // Subtraction operator
    Graph Graph::operator-(const Graph& other) const {
        if (numVertices != other.numVertices) {
            throw std::invalid_argument("Graphs must be of the same size for subtraction.");
        }
        Graph result;
        result.numVertices = numVertices;
        result.isDirected = isDirected;
        result.adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                result.adjacencyMatrix[i][j] = adjacencyMatrix[i][j] - other.adjacencyMatrix[i][j];
            }
        }
        return result;
    }

    // Subtraction assignment operator
    Graph& Graph::operator-=(const Graph& other) {
        if (numVertices != other.numVertices) {
            throw std::invalid_argument("Graphs must be of the same size for subtraction.");
        }
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                adjacencyMatrix[i][j] -= other.adjacencyMatrix[i][j];
            }
        }
        return *this;
    }

    // Unary plus operator
    Graph Graph::operator+() const {
        return *this;
    }

    // Unary minus operator
    Graph Graph::operator-() const {
        Graph result;
        result.numVertices = numVertices;
        result.isDirected = isDirected;
        result.adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                result.adjacencyMatrix[i][j] = -adjacencyMatrix[i][j];
            }
        }
        return result;
    }

    // Comparison operators
    bool Graph::operator==(const Graph& other) const {
        return (numVertices == other.numVertices && adjacencyMatrix == other.adjacencyMatrix);
    }

    bool Graph::operator!=(const Graph& other) const {
        return !(*this == other);
    }

    bool Graph::operator>(const Graph& other) const {
        if (*this == other) return false;
        if (numEdges > other.numEdges) return true;
        if (numEdges < other.numEdges) return false;
        return adjacencyMatrix > other.adjacencyMatrix;
    }

    bool Graph::operator>=(const Graph& other) const {
        return (*this > other || *this == other);
    }

    bool Graph::operator<(const Graph& other) const {
        return !(*this >= other);
    }

    bool Graph::operator<=(const Graph& other) const {
        return !(*this > other);
    }

    // Prefix increment operator
    Graph& Graph::operator++() {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                ++adjacencyMatrix[i][j];
            }
        }
        return *this;
    }

    // Postfix increment operator
    Graph Graph::operator++(int) {
        Graph temp = *this;
        ++(*this);
        return temp;
    }

    // Prefix decrement operator
    Graph& Graph::operator--() {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                --adjacencyMatrix[i][j];
            }
        }
        return *this;
    }

    // Postfix decrement operator
    Graph Graph::operator--(int) {
        Graph temp = *this;
        --(*this);
        return temp;
    }

    // Multiplication by an integer scalar
    Graph Graph::operator*(int scalar) const {
        Graph result;
        result.numVertices = numVertices;
        result.isDirected = isDirected;
        result.adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                result.adjacencyMatrix[i][j] = adjacencyMatrix[i][j] * scalar;
            }
        }
        return result;
    }

    Graph& Graph::operator*=(int scalar) {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                adjacencyMatrix[i][j] *= scalar;
            }
        }
        return *this;
    }

    // Graph multiplication
    Graph Graph::operator*(const Graph& other) const {
        if (numVertices != other.numVertices) {
            throw std::invalid_argument("Graphs must be of the same size for multiplication.");
        }
        Graph result;
        result.numVertices = numVertices;
        result.isDirected = isDirected;
        result.adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                for (int k = 0; k < numVertices; ++k) {
                    result.adjacencyMatrix[i][j] += adjacencyMatrix[i][k] * other.adjacencyMatrix[k][j];
                }
            }
        }
        return result;
    }

    // Output operator
   // Output operator
std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    os << "Graph with " << graph.numVertices << " vertices and " << graph.numEdges << " edges";
    if (graph.isDirected) {
        os << " (Directed)" << std::endl;
    } else {
        os << " (Undirected)" << std::endl;
    }
    for (int i = 0; i < graph.numVertices; ++i) {
        for (int j = 0; j < graph.numVertices; ++j) {
            os << graph.adjacencyMatrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

}
