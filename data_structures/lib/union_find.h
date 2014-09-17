#ifndef __UNION_FIND_H__
#define __UNION_FIND_H__

/*
    Union-Find data structure, used to keep track of dynamic percolation
*/
#include "vector"

class UnionFind{
    private:
        std::vector<unsigned> id_, weight_;
    public:
        UnionFind(unsigned N);
        void Reset(void); // disconnect all the items
        unsigned Find(unsigned i); // return the ID of the ith item
        void Union(unsigned i, unsigned j);
        void PrintID(void); // print the ID list. For testing only.
};

#endif
