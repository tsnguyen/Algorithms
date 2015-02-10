/*=============================================================================
    C++ implementation of the Kruskal's algorithm for minimum cost spanning
    tree.

    Input   : a connected graph with a cost for each edge.
    Output  : a tree that connects all the nodes with minimum cost.

    At every iteration, the program will attempt to add the edge with lowest
    cost available to the tree such that no loop is formed.

    We use heap structure to maintain the sorted list of available edges, and
    use union-find structure to keep track of the cluster each node belongs to.


=============================================================================*/

#ifndef __KRUSKAL_H__
#define __KRUSKAL_H__

#include "tree.h"
#include "heap.h"

Tree KruskalMST(Graph &graph){
    unsigned numberOfNodes = graph.GetNumNodes();
    unsigned numberOfEdges = graph.GetNumEdges();
    std::vector<long> e;
    unsigned clusterSize;
    Tree tree(numberOfNodes);

    Heap edges(2,3); // each edge is an 1 by 3 vector with the cost is  stored
                     // in the last element

    for (unsigned i = 0; i < numberOfEdges; i++)
        edges.Add(graph.GetEdge(i));

    for (unsigned i = 0; i < numberOfEdges; i++){
        e = edges.Pop();
        clusterSize = tree.AddEdge(e);
        if (clusterSize == numberOfNodes)
            break;
    }
    if (clusterSize < numberOfNodes)
        std::cerr << "The graph is not connected \n";
    return tree;
}

#endif
