/*=============================================================================
                    The tree class

    A tree is a graph without any loop. This extra property is maintained by
    a union-find structure.

=============================================================================*/

#ifndef __TREE_H__
#define __TREE_H__

#include "graph.h"
#include "unionfind.h"

class Tree : public Graph{
    private:
        unsigned mMaxNumNodes;
        UnionFind mUF;
    public:
        Tree(unsigned);
        void Randomize(long, long);
        unsigned AddEdge(unsigned, unsigned, long);
        unsigned AddEdge(std::vector<long> &);
};

#endif
