#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <stdexcept>

namespace ariel {
    class Graph {
    public:
        Graph();
       
        void loadGraph(const std::vector<std::vector<int>>& graph);
        void printGraph() const;
        int getNumVertices() const;
        int getNumEdges() const;
        const std::vector<std::vector<int>>& getAdjacencyMatrix() const;

        // Operator overloading
        Graph operator+(const Graph& other) const;
        Graph& operator+=(const Graph& other);
        Graph operator-(const Graph& other) const;
        Graph& operator-=(const Graph& other);
        Graph operator+() const;
        Graph operator-() const;

        // Comparison operators
        bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;
        bool operator>(const Graph& other) const;
        bool operator>=(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;

        // Increment and decrement operators
        Graph& operator++();    // Prefix increment
        Graph operator++(int);  // Postfix increment
        Graph& operator--();    // Prefix decrement
        Graph operator--(int);  // Postfix decrement
  // Multiplication operators
        Graph operator*(int scalar) const;
        Graph& operator*=(int scalar);
        Graph operator*(const Graph& other) const;

        // Output operator
        friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
    private:
        int numVertices;
        int numEdges;
        bool isDirected;
        std::vector<std::vector<int>> adjacencyMatrix;
    };
}

#endif
