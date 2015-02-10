/*=============================================================================
                    Union-Find Data Structure

        Keep track of connected clusters of a set of elements. Each element
        points to its leader, and the leader of the entire cluster points to
        itself.

=============================================================================*/

#ifndef __UNIONFIND_H__
#define __UNIONFIND_H__

#include "vector"

class UnionFind{
    private:
        std::vector< std::vector<unsigned> > mUFData;
        /*
        The data is tored in a (n x 2) matrix, where the first column is the
        leader, and the second column is the size of the cluster when the index
        and the leader are the same. For example, if the element 4 is {15, 5},
        it would mean element 4th has 15 as a leader. We then access element 15
        and get {15, 8}, it would mean 15 is a leader of itself, and therefore
        the leader of the entire group, which has 8 elements.
        */
    public:
        UnionFind(unsigned);
        unsigned Find(unsigned);
        unsigned Union(unsigned, unsigned);
};

#endif
