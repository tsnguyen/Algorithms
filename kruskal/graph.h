/*=============================================================================
                    The Graph class
=============================================================================*/

#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "vector"
#include "iostream"
#include "fstream"
#include "random"

class Graph{
    private:
        std::vector< std::vector<long> > mGraphData;
        unsigned mNodes; // Number of nodes
        std::vector<bool> mIsOccupied; // Occupation status of possible nodes
    public:
        // Construct an empty graph with a max capacity for number of nodes
        Graph(unsigned);
        // Randomly initialize all the edges
        void Randomize(long , long);
        // Add an edge to the graph, update the list of occupied nodes
        void AddEdge(unsigned , unsigned , long);
        void AddEdge(std::vector<long>&);
        // Add a node the the graph
        void AddNode(unsigned);
        // Checkc if a node is in the graph
        bool IsContain(unsigned);
        // Store the graph in a file (csv by default)
        void Store(std::string fileName = "temp.csv", char sep = ',');

        // Data access methods
        unsigned GetNumNodes(void){ return mNodes; }
        unsigned GetNumEdges(void){ return mGraphData.size(); }
        std::vector<long> GetEdge(unsigned i){ return mGraphData[i]; }

};

#endif
