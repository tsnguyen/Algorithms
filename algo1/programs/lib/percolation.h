/*
    Generate a grid of boolean of size N * N to represent a percolation
    process.
*/
#ifndef __PERCOLATION_H__
#define __PERCOLATION_H__

#include "../../data_structures/lib/union_find.h"

class Percolation{
    private:
        unsigned edge_length_;
        std::vector<bool> grid_;
        UnionFind *p_uf_;
        bool IsOpen(unsigned i, unsigned j);
        void Reset(void);
    public:
        Percolation(unsigned N);
        // generate the grid and setup the cluster counting
        ~Percolation(void);
        unsigned Open(unsigned i, unsigned j);
        // if the site is not yet opened, open it and return 1, else return 0
        bool IsPercolate(void);
        // check if the upper bound and the lower bound of the grid are
        // connected
        unsigned RandomPercolate(void);
        // Randomly add open site into the grid until the grid is percolate
        void ExportPercolationThreshold(unsigned N = 1000,
                                        std::string = "tmp/percolation.csv");
        // Run the random percolation N times, and record the required number
        // of open sites to a csv file
        void PrintGrid(void);
        // Print the current status of the grid. For testing only.
};

#endif
