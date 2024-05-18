#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.hpp"
#include <vector>
#include <stdexcept>
#include <sstream>
using namespace ariel;
using namespace std;

TEST_SUITE("Graph Arithmetic Operators Tests") {
    TEST_CASE("Addition of graphs") {
        vector<vector<int>> adjMatrix1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };

        vector<vector<int>> adjMatrix2 = {
            {0, 0, 1},
            {0, 0, 0},
            {1, 0, 0}
        };

        Graph graph1;
        graph1.loadGraph(adjMatrix1);

        Graph graph2;
        graph2.loadGraph(adjMatrix2);

        Graph result = graph1 + graph2;
        vector<vector<int>> expectedMatrix = {
            {0, 1, 1},
            {1, 0, 1},
            {1, 1, 0}
        };

        CHECK(result.getAdjacencyMatrix() == expectedMatrix);
    }

    TEST_CASE("Addition assignment of graphs") {
        vector<vector<int>> adjMatrix1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };

        vector<vector<int>> adjMatrix2 = {
            {0, 0, 1},
            {0, 0, 0},
            {1, 0, 0}
        };

        Graph graph1;
        graph1.loadGraph(adjMatrix1);

        Graph graph2;
        graph2.loadGraph(adjMatrix2);

        graph1 += graph2;
        vector<vector<int>> expectedMatrix = {
            {0, 1, 1},
            {1, 0, 1},
            {1, 1, 0}
        };

        CHECK(graph1.getAdjacencyMatrix() == expectedMatrix);
    }

    TEST_CASE("Subtraction of graphs") {
        vector<vector<int>> adjMatrix1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };

        vector<vector<int>> adjMatrix2 = {
            {0, 0, 1},
            {0, 0, 0},
            {1, 0, 0}
        };

        Graph graph1;
        graph1.loadGraph(adjMatrix1);

        Graph graph2;
        graph2.loadGraph(adjMatrix2);

        Graph result = graph1 - graph2;
        vector<vector<int>> expectedMatrix = {
            {0, 1, -1},
            {1, 0, 1},
            {-1, 1, 0}
        };

        CHECK(result.getAdjacencyMatrix() == expectedMatrix);
    }

    TEST_CASE("Subtraction assignment of graphs") {
        vector<vector<int>> adjMatrix1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };

        vector<vector<int>> adjMatrix2 = {
            {0, 0, 1},
            {0, 0, 0},
            {1, 0, 0}
        };

        Graph graph1;
        graph1.loadGraph(adjMatrix1);

        Graph graph2;
        graph2.loadGraph(adjMatrix2);

        graph1 -= graph2;
        vector<vector<int>> expectedMatrix = {
            {0, 1, -1},
            {1, 0, 1},
            {-1, 1, 0}
        };

        CHECK(graph1.getAdjacencyMatrix() == expectedMatrix);
    }

    TEST_CASE("Unary plus operator") {
        vector<vector<int>> adjMatrix1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };

        Graph graph1;
        graph1.loadGraph(adjMatrix1);

        Graph result = +graph1;

        CHECK(result.getAdjacencyMatrix() == graph1.getAdjacencyMatrix());
    }

    TEST_CASE("Unary minus operator") {
        vector<vector<int>> adjMatrix1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };

        Graph graph1;
        graph1.loadGraph(adjMatrix1);

        Graph result = -graph1;
        vector<vector<int>> expectedMatrix = {
            {0, -1, 0},
            {-1, 0, -1},
            {0, -1, 0}
        };

        CHECK(result.getAdjacencyMatrix() == expectedMatrix);
    }

    TEST_CASE("Size mismatch exception") {
        vector<vector<int>> adjMatrix1 = {
            {0, 1},
            {1, 0}
        };

        vector<vector<int>> adjMatrix2 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };

        Graph graph1;
        graph1.loadGraph(adjMatrix1);

        Graph graph2;
        graph2.loadGraph(adjMatrix2);

        CHECK_THROWS_AS(graph1 + graph2, invalid_argument);
        CHECK_THROWS_AS(graph1 += graph2, invalid_argument);
        CHECK_THROWS_AS(graph1 - graph2, invalid_argument);
        CHECK_THROWS_AS(graph1 -= graph2, invalid_argument);
    }
}

TEST_SUITE("Graph Comparison Operators Tests") {
    TEST_CASE("Equality operator") {
        vector<vector<int>> adjMatrix1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };

        vector<vector<int>> adjMatrix2 = {
            {0, 1, 0},
            {1, 0, 0},
            {0, 0, 0}
        };

        Graph graph1;
        graph1.loadGraph(adjMatrix1);

        Graph graph2;
        graph2.loadGraph(adjMatrix2);

        CHECK((graph1 == graph1) == true);
        CHECK((graph1 == graph2) == false);
    }

    TEST_CASE("Inequality operator") {
        vector<vector<int>> adjMatrix1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };

        vector<vector<int>> adjMatrix2 = {
            {0, 1, 0},
            {1, 0, 0},
            {0, 0, 0}
        };

        Graph graph1;
        graph1.loadGraph(adjMatrix1);

        Graph graph2;
        graph2.loadGraph(adjMatrix2);

        CHECK((graph1 != graph2) == true);
        CHECK((graph1 != graph1) == false);
    }

    TEST_CASE("Greater than operator") {
        vector<vector<int>> adjMatrix1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };

        vector<vector<int>> adjMatrix2 = {
            {0, 1, 0},
            {1, 0, 0},
            {0, 0, 0}
        };

        Graph graph1;
        graph1.loadGraph(adjMatrix1);

        Graph graph2;
        graph2.loadGraph(adjMatrix2);

        CHECK((graph1 > graph2) == true);
        CHECK((graph2 > graph1) == false);
    }

    TEST_CASE("Greater than or equal operator") {
        vector<vector<int>> adjMatrix1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };

        vector<vector<int>> adjMatrix2 = {
            {0, 1, 0},
            {1, 0, 0},
            {0, 0, 0}
        };

        Graph graph1;
        graph1.loadGraph(adjMatrix1);

        Graph graph2;
        graph2.loadGraph(adjMatrix2);

        CHECK((graph1 >= graph2) == true);
        CHECK((graph2 >= graph1) == false);
        CHECK((graph1 >= graph1) == true);
    }

    TEST_CASE("Less than operator") {
        vector<vector<int>> adjMatrix1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };

        vector<vector<int>> adjMatrix2 = {
            {0, 1, 0},
            {1, 0, 0},
            {0, 0, 0}
        };

        Graph graph1;
        graph1.loadGraph(adjMatrix1);

        Graph graph2;
        graph2.loadGraph(adjMatrix2);

        CHECK((graph2 < graph1) == true);
        CHECK((graph1 < graph2) == false);
    }

    TEST_CASE("Less than or equal operator") {
        vector<vector<int>> adjMatrix1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };

        vector<vector<int>> adjMatrix2 = {
            {0, 1, 0},
            {1, 0, 0},
            {0, 0, 0}
        };

        Graph graph1;
        graph1.loadGraph(adjMatrix1);

        Graph graph2;
        graph2.loadGraph(adjMatrix2);

        CHECK((graph2 <= graph1) == true);
        CHECK((graph1 <= graph2) == false);
        CHECK((graph1 <= graph1) == true);
    }
}

TEST_SUITE("Graph Increment and Decrement Operators Tests") {
    TEST_CASE("Prefix increment operator") {
        vector<vector<int>> adjMatrix = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };

        Graph graph;
        graph.loadGraph(adjMatrix);

        ++graph;
        vector<vector<int>> expectedMatrix = {
            {1, 2, 1},
            {2, 1, 2},
            {1, 2, 1}
        };
        CHECK(graph.getAdjacencyMatrix() == expectedMatrix);
    }

    TEST_CASE("Postfix increment operator") {
        vector<vector<int>> adjMatrix = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };

        Graph graph;
        graph.loadGraph(adjMatrix);

        graph++;
        vector<vector<int>> expectedMatrix = {
            {1, 2, 1},
            {2, 1, 2},
            {1, 2, 1}
        };
        CHECK(graph.getAdjacencyMatrix() == expectedMatrix);
    }

    TEST_CASE("Prefix decrement operator") {
        vector<vector<int>> adjMatrix = {
            {1, 2, 1},
            {2, 1, 2},
            {1, 2, 1}
        };

        Graph graph;
        graph.loadGraph(adjMatrix);

        --graph;
        vector<vector<int>> expectedMatrix = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };
        CHECK(graph.getAdjacencyMatrix() == expectedMatrix);
    }

    TEST_CASE("Postfix decrement operator") {
        vector<vector<int>> adjMatrix = {
            {1, 2, 1},
            {2, 1, 2},
            {1, 2, 1}
        };

        Graph graph;
        graph.loadGraph(adjMatrix);

        graph--;
        vector<vector<int>> expectedMatrix = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };
        CHECK(graph.getAdjacencyMatrix() == expectedMatrix);
    }
}

TEST_SUITE("Graph Multiplication Operators Tests") {
    TEST_CASE("Scalar multiplication") {
        vector<vector<int>> adjMatrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        Graph graph;
        graph.loadGraph(adjMatrix);

        Graph result = graph * 2;
        vector<vector<int>> expectedMatrix = {
            {2, 4, 6},
            {8, 10, 12},
            {14, 16, 18}
        };
        CHECK(result.getAdjacencyMatrix() == expectedMatrix);

        graph *= 3;
        expectedMatrix = {
            {3, 6, 9},
            {12, 15, 18},
            {21, 24, 27}
        };
        CHECK(graph.getAdjacencyMatrix() == expectedMatrix);
    }

    TEST_CASE("Graph multiplication") {
        vector<vector<int>> adjMatrix1 = {
            {1, 2},
            {3, 4}
        };

        vector<vector<int>> adjMatrix2 = {
            {5, 6},
            {7, 8}
        };

        Graph graph1;
        graph1.loadGraph(adjMatrix1);

        Graph graph2;
        graph2.loadGraph(adjMatrix2);

        Graph result = graph1 * graph2;
        vector<vector<int>> expectedMatrix = {
            {19, 22},
            {43, 50}
        };
        CHECK(result.getAdjacencyMatrix() == expectedMatrix);

        vector<vector<int>> adjMatrix3 = {
            {1, 2, 3},
            {4, 5, 6}
        };

        Graph graph3;
        try
        {
                    graph3.loadGraph(adjMatrix3);

        }
        catch(const std::exception& e)
        {
            std::cout << "trying to load non square matrix should get Error: "  << '\n';
            std::cerr << e.what() << '\n';
        }
        
    

        CHECK_THROWS_AS(graph1 * graph3, invalid_argument);
    }
}

TEST_SUITE("Graph Output Operator Tests") {
    TEST_CASE("Output operator") {
        vector<vector<int>> adjMatrix = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };

        Graph graph;
        graph.loadGraph(adjMatrix);

        ostringstream os;
        os << graph;

        string expectedOutput = "Graph with 3 vertices and 2 edges (Undirected)\n"
                                "0 1 0 \n"
                                "1 0 1 \n"
                                "0 1 0 \n";

        CHECK(os.str() == expectedOutput);
    }
}
