/*
    Last update: July 27 2014

    Test the Kruskal algorithm for minimum spanning tree with random graphs.

*/
#include "stdlib.h"
#include "time.h"
#include "kruskal.h"

int main(void){
    /*
    Test the Kruskal algorithm:
        1. Generate a graph with random edge costs
        2. Store the graph (for future comparision)
        3. Compute the MST of the graph.
        4. Store the MST.
    */
    srand (time(NULL));
    Graph graph(1000);
    graph.Randomize(-10000, 10000);
    graph.Store("graph.csv");

    KruskalMST(graph).Store("tree.csv");

    return 0;
}