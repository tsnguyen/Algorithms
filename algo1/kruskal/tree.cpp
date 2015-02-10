#include "tree.h"

Tree::Tree(unsigned maxSize) : Graph(maxSize), mUF(maxSize){
    mMaxNumNodes = maxSize;
}

void Tree::Randomize(long edgeMin, long edgeMax){
    unsigned node1, node2, size = 1, edge, leader1, leader2;
    do{
        node1   =   rand() % mMaxNumNodes;
        node2   =   rand() % mMaxNumNodes;
        edge    =   rand() % (edgeMax - edgeMin) + edgeMin;
        size    =   AddEdge(node1, node2, edge);
    } while(size < mMaxNumNodes);
}

unsigned Tree::AddEdge(unsigned node1, unsigned node2, long cost){
    long v[3] = {node1, node2, cost};
    std::vector<long> edge(v, v + 3);
    return AddEdge(edge);
}

unsigned Tree::AddEdge(std::vector<long> &edge){
    unsigned leader1, leader2;

    leader1 = mUF.Find(edge[0]);
    leader2 = mUF.Find(edge[1]);

    if(leader1 != leader2){
        Graph::AddEdge(edge);
        return mUF.Union(leader1, leader2);
    }
    else
        return 0;
}

