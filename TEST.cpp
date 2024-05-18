#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;
#include <iostream>
#include <stdexcept>
#include <cassert>
#include <vector>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
using namespace std;

TEST_SUITE("isConnected tests") {
    ariel::Graph g;

    TEST_CASE("Testing the isConnected function Undirected") {
        cout << "Starting tests" << endl;
        cout << "testing isconnected()" << endl;

        // Undirected unweighted graph (connected)
        vector<vector<int>> undirectedUnweighted = {
                {0, 1, 0, 0},
                {1, 0, 1, 0},
                {0, 1, 0, 1},
                {0, 0, 1, 0}
        };
        g.loadGraph(undirectedUnweighted);
        g.printGraph();
        CHECK(ariel::Algorithms::isConnected(g) == true); // Expect true
    }

    TEST_CASE("Testing the isConnected function undirected") {
        // Undirected weighted graph (connected)
        vector<vector<int>> undirectedWeighted = {
                {0, 2, 0, 6},
                {2, 0, 3, 0},
                {0, 3, 0, 1},
                {6, 0, 1, 0}
        };
        g.loadGraph(undirectedWeighted);
        g.printGraph();
        CHECK(ariel::Algorithms::isConnected(g) == true);  // Expect true
    }

    TEST_CASE("Testing the isConnected function Directed cyclic") {
        // Directed unweighted graph (cyclic)
        vector<vector<int>> directedUnweighted = {
                {0, 1, 0, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 1},
                {1, 0, 0, 0}
        };
        g.loadGraph(directedUnweighted);
        g.printGraph();
        CHECK(ariel::Algorithms::isConnected(g) == true); // Expect true
    }

    TEST_CASE("Testing the isConnected function Directed cyclic") {
        // Directed weighted graph (cyclic)
        vector<vector<int>> directedWeighted = {
                {0, 4, 0, 0},
                {0, 0, 5, 0},
                {0, 0, 0, 2},
                {1, 0, 0, 0}
        };
        g.loadGraph(directedWeighted);
        g.printGraph();
        CHECK(ariel::Algorithms::isConnected(g) == true); // Expect true
    }

    TEST_CASE("Testing the isConnected function on Disconnected Undirected") {
        // Disconnected graphs
        // Undirected unweighted disconnected graph
        vector<vector<int>> undirectedUnweightedDisconnected = {
                {0, 1, 0, 0},
                {1, 0, 0, 0},
                {0, 0, 0, 1},
                {0, 0, 1, 0}
        };
        g.loadGraph(undirectedUnweightedDisconnected);
        g.printGraph();
        CHECK(ariel::Algorithms::isConnected(g) == false); // Expect false
    }
}

TEST_SUITE("shortestPath tests") {
    ariel::Graph graph;

    TEST_CASE("Testing the shortestPath1 function") {
        // Directed unweighted graph (cyclic)
        vector<vector<int>> directedUnweightedShortest = {
                {0, 1, 0, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 1},
                {1, 0, 0, 0}
        };
        graph.loadGraph(directedUnweightedShortest);
        graph.printGraph();
        string shortestPath3 = Algorithms::shortestPath(graph, 0, 3);
        CHECK(shortestPath3 == "0->1->2->3");
        cout << "Shortest path from 0 to 3: " << shortestPath3 << endl;
    }

TEST_CASE("Testing the shortestPath2 function") {

    // Undirected unweighted graph (connected)
    vector<vector<int>> undirectedUnweighted1 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}
    };
    graph.loadGraph(undirectedUnweighted1);
    graph.printGraph();
    CHECK(Algorithms::shortestPath(graph, 0, 3)=="0->1->2->3");// Should print: "0 -> 1 -> 2 -> 3"


}

TEST_CASE("Testing the shortestPath3 function") {
    // Undirected weighted graph (connected)
    vector<vector<int>> undirectedWeightedShortest = {
        {0, 2, 0, 6},
        {2, 0, 2, 0},
        {0, 3, 0, 1},
        {6, 0, 1, 0}
    };
    graph.loadGraph(undirectedWeightedShortest);
    graph.printGraph();   
    CHECK(Algorithms::shortestPath(graph, 0, 2) == "0->1->2");

}


TEST_CASE("Testing the shortestPath4 function") {
    // Directed weighted graph (cyclic)
    vector<vector<int>> directedWeightedShortest = {
        {0, 4, 0, 0},
        {0, 0, 5, 0},
        {0, 0, 0, 2},
        {1, 0, 0, 0}
    };
    graph.loadGraph(directedWeightedShortest);
    graph.printGraph();
    string shortestPath4 = Algorithms::shortestPath(graph, 0, 3);
    CHECK(shortestPath4 == "0->1->2->3");

}
}



TEST_SUITE("iscontainscycle tests") {
    ariel::Graph g;


TEST_CASE("Testing the iscontainscycle function") {

    // Undirected unweighted graph (connected)
    vector<vector<int>> undirectedUnweightedCycle = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}
    };
    g.loadGraph(undirectedUnweightedCycle);
    g.printGraph();
    CHECK(Algorithms::isContainsCycle(g) == "0");  // Expect false
}

TEST_CASE("Testing the iscontainscycle function") {

    // Undirected weighted graph (connected)
    vector<vector<int>> undirectedWeightedCycle = {
        {0, 2, 0, 6},
        {2, 0, 3, 0},
        {0, 3, 0, 1},
        {6, 0, 1, 0}
    };
    g.loadGraph(undirectedWeightedCycle);
    g.printGraph();
    CHECK(Algorithms::isContainsCycle(g) == "0->1->2->3->0");  // Expect false

}

TEST_CASE("Testing the iscontainscycle function") {
  // Directed unweighted graph (cyclic)
    vector<vector<int>> directedUnweightedCycle = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}
    };
    g.loadGraph(directedUnweightedCycle);
    g.printGraph();

    CHECK(Algorithms::isContainsCycle(g) == "0->1->2->3->0");  // Expect true

}

TEST_CASE("Testing the iscontainscycle function") {
        // Directed weighted graph (cyclic)
    vector<vector<int>> directedWeightedCycle = {
        {0, 4, 0, 0},
        {0, 0, 5, 0},
        {0, 0, 0, 2},
        {1, 0, 0, 0}
    };
    g.loadGraph(directedWeightedCycle);
    g.printGraph();
    CHECK(Algorithms::isContainsCycle(g) == "0->1->2->3->0");  // Expect true

}

TEST_CASE("Testing the iscontainscycle function") {
        // Disconnected graphs
    // Undirected unweighted disconnected graph
    vector<vector<int>> undirectedUnweightedDisconnectedCycle = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}
    };
    g.loadGraph(undirectedUnweightedDisconnectedCycle);
    g.printGraph();
    assert(Algorithms::isContainsCycle(g) == "0");  // Expect false

}
}

TEST_SUITE("negativecycle tests") {

    ariel::Graph g;


TEST_CASE("Testing the negativecycle1 function") {
    // Undirected unweighted graph (connected)
    vector<vector<int>> undirectedUnweightedNegative = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}
    };
    g.loadGraph(undirectedUnweightedNegative);
    g.printGraph();
    cout << Algorithms::negativeCycle(g) << endl;
    CHECK(Algorithms::negativeCycle(g) == "0");  // Expect false
}
TEST_CASE("Testing the negativecycle2 function") {
        // Undirected weighted graph (connected)
    vector<vector<int>> undirectedWeightedNegative = {
        {0, 2, 0, 6},
        {2, 0, 3, 0},
        {0, 3, 0, 1},
        {6, 0, 1, 0}
    };

    g.loadGraph(undirectedWeightedNegative);
    g.printGraph();
    CHECK(Algorithms::negativeCycle(g) == "0");  // Expect false

}
TEST_CASE("Testing the negativecycle3 function") {
        // Directed unweighted graph (cyclic)
    vector<vector<int>> directedUnweightedNegative = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}
    };
    g.loadGraph(directedUnweightedNegative);
    g.printGraph();
    CHECK(Algorithms::negativeCycle(g) == "0");  // Expect false

}
TEST_CASE("Testing the negativecycle4 function") {
        // Directed weighted graph (cyclic)
    vector<vector<int>> directedWeightedNegative = {
        {0, -4, 0, 0},
        {0, 0, 5, 0},
        {0, 0, 0, -2},
        {-1, 0, 0, 0}
    };

    g.loadGraph(directedWeightedNegative);
    g.printGraph();
    cout << Algorithms::negativeCycle(g) << endl;
    CHECK(Algorithms::negativeCycle(g) == "0->1->2->3->0");  // Expect false

}

TEST_CASE("Testing the negativecycle5 function") {
    // Disconnected graphs
    // Undirected unweighted disconnected graph
    vector<vector<int>> undirectedUnweightedDisconnectedNegative = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}
    };
    g.loadGraph(undirectedUnweightedDisconnectedNegative);

    g.printGraph();
    CHECK(Algorithms::negativeCycle(g) == "0");  // Expect false

}


}




TEST_SUITE("isbipartite tests") {

    ariel::Graph g;

TEST_CASE("Testing the isbipartite1 function") {
    // Undirected unweighted graph (connected)
    vector<vector<int>> undirectedUnweightedBipartite = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}
    };
    g.loadGraph(undirectedUnweightedBipartite);
    g.printGraph();
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}.");

}
TEST_CASE("Testing the isbipartite2 function") {
        // Undirected weighted graph (connected)
    vector<vector<int>> treeBipartite = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };
    g.loadGraph(treeBipartite);
    g.printGraph();
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 3}, B={1, 4}.");  // Expect true because it's bipartite

}
TEST_CASE("Testing the isbipartite3 function") {
        vector<vector<int>> noddCycleGraph = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };
    g.loadGraph(noddCycleGraph);
    g.printGraph();
    cout << "Is Bipartite: " << Algorithms::isBipartite(g) << endl; 

    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}.");  

}
TEST_CASE("Testing the isbipartite4 function") {
        vector<vector<int>> oddCycleGraph = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}
    };
    g.loadGraph(oddCycleGraph);
    g.printGraph();
    cout << " " << Algorithms::isBipartite(g) << endl; 

    CHECK(Algorithms::isBipartite(g) == "The graph is not bipartite.");  // Expect false because it's not bipartite

}

}



