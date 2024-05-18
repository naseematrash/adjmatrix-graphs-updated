# Graph and Algorithms: A C++ Implementation

## Introduction
This C++ project showcases the implementation of two fundamental classes: `Graph` and `Algorithms`. The `Graph` class represents a graph data structure, supporting both directed and undirected graphs, using an adjacency matrix for edge representation. The `Algorithms` class offers a suite of graph-theoretic operations, including connectivity checks, shortest path calculations, cycle detection, and more, all designed to seamlessly integrate with the `Graph` class.

## Project Structure
The project is organized into the following source files:
- `graph.hpp`: Defines the `Graph` class interface.
- `graph.cpp`: Implements the `Graph` class functionality.
- `algorithms.hpp`: Defines the `Algorithms` class interface.
- `algorithms.cpp`: Implements the `Algorithms` class functionality.
- (Include any additional source files here)

## The `Graph` Class
The `Graph` class encapsulates the graph data structure and provides the following key features:

### Constructors
- **Graph()**: Default constructor that initializes a graph, assumed to be directed unless specified otherwise.

### Member Functions
- **loadGraph(const std::vector<std::vector<int>>&)**: Loads a graph from a square adjacency matrix, automatically detecting if the graph is undirected based on matrix symmetry.
- **printGraph() const**: Outputs the graph's properties and its adjacency matrix.
- **getNumVertices() const**: Returns the number of vertices in the graph.
- **getNumEdges() const**: Returns the number of edges in the graph.
- **getAdjacencyMatrix() const**: Provides read-only access to the graph's adjacency matrix.

### Private Members
- `int numVertices`: Stores the number of vertices in the graph.
- `int numEdges`: Stores the number of edges in the graph.
- `bool isDirected`: Indicates whether the graph is directed or undirected.
- `std::vector<std::vector<int>> adjacencyMatrix`: Represents the graph's adjacency matrix.

## The `Algorithms` Class
The `Algorithms` class offers a collection of static methods for performing various graph-theoretic operations on `Graph` objects:

### Public Static Methods
- **isConnected(const Graph &)**: Checks if the graph is connected, i.e., if there exists a path from any vertex to any other vertex. It employs a depth-first search (DFS) starting from a vertex with a non-zero out-degree and attempts to visit all vertices.
- **shortestPath(const Graph &, int, int)**: Computes the shortest path between two vertices in a weighted graph. It can handle graphs with negative edge weights and detects negative weight cycles that would prevent the existence of a shortest path.
- **isContainsCycle(const Graph &)**: Checks for the presence of cycles in the graph using a DFS-based approach.
- **negativeCycle(const Graph &)**: Searches for negative-weight cycles in the graph using the Bellman-Ford algorithm.
- **isBipartite(const Graph &)**: Determines if the graph is bipartite, i.e., if its vertices can be divided into two disjoint sets such that no two vertices within the same set are adjacent. It uses a modified breadth-first search (BFS) algorithm.

### Private Static Methods
- **hasCycleHelper(const Graph&, int, std::vector<bool>&, int, std::vector<int>&)**: A utility function used by the `isContainsCycle` method to perform the DFS traversal for cycle detection.

## Usage Examples
Here's an example of how to use the `Graph` and `Algorithms` classes:
## Usage Examples
compile command -:make
run:./DemoApp
```cpp
#include "graph.hpp"
#include <iostream>
#include <vector>

int main() {
    ariel::Graph myGraph;
    std::vector<std::vector<int>> matrix = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}
    };

    try {
        myGraph.loadGraph(matrix);
        myGraph.printGraph();
        assert(Algorithms::negativeCycle(g) == "0"); // Expect false
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
```

In this example, we create a `Graph` object, load an adjacency matrix into it, print the graph's properties, and check for the presence of negative-weight cycles using the `negativeCycle` method from the `Algorithms` class.

Feel free to explore the various functionalities provided by the `Graph` and `Algorithms` classes to analyze and manipulate graphs efficiently in your C++ projects!



Graph Operators Implementation Overview
The Graph class includes a variety of operators that enable arithmetic and logical operations on graph objects. These graphs are represented using adjacency matrices, allowing for matrix operations.

Addition and Subtraction Operators
Addition Operator (+): Adds corresponding elements of the adjacency matrices of two graphs. Throws an exception if the graphs are not of the same size.
Addition Assignment Operator (+=): Adds corresponding elements of another graph's adjacency matrix to the current graph. Throws an exception if the graphs are not of the same size.
Subtraction Operator (-): Subtracts corresponding elements of the adjacency matrices of another graph from the current graph. Throws an exception if the graphs are not of the same size.
Subtraction Assignment Operator (-=): Subtracts corresponding elements of another graph's adjacency matrix from the current graph. Throws an exception if the graphs are not of the same size.
Unary Operators
Unary Plus Operator (+): Returns the graph as-is.
Unary Minus Operator (-): Negates the elements of the adjacency matrix.
Comparison Operators
Equality Operator (==): Checks if two graphs are identical.
Inequality Operator (!=): Checks if two graphs are not identical.
Greater Than Operator (>): Checks if one graph is greater than another based on the number of edges or matrix elements.
Greater Than or Equal Operator (>=): Checks if one graph is greater than or equal to another.
Less Than Operator (<): Checks if one graph is less than another.
Less Than or Equal Operator (<=): Checks if one graph is less than or equal to another.
Increment and Decrement Operators
Prefix Increment Operator (++): Increments each element of the adjacency matrix by 1.
Postfix Increment Operator (++(int)): Increments each element of the adjacency matrix by 1 and returns the original graph.
Prefix Decrement Operator (--): Decrements each element of the adjacency matrix by 1.
Postfix Decrement Operator (--(int)): Decrements each element of the adjacency matrix by 1 and returns the original graph.
Multiplication Operators
Multiplication by an Integer Scalar (*): Multiplies each element of the adjacency matrix by a scalar.
Graph Multiplication (*): Multiplies the adjacency matrices of two graphs. Throws an exception if the graphs are not of the same size.
Output Operator
Output Operator (<<): Prints the graph in a human-readable format.
These operators enhance the functionality of the Graph class, enabling a wide range of arithmetic and logical operations while ensuring proper handling of invalid operations through appropriate checks and exceptions.

to run:
compile command -:  make
run command -:   ./GraphTests