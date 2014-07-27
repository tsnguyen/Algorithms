#include "graph.h"

void Graph::Randomize(long edgeMin, long edgeMax){
    mGraphData.clear();
    unsigned n = mIsOccupied.size();
    for (unsigned i = 0; i < n; i++){
        for (unsigned j = i + 1; j < n; j++){
            long v[3] = {i, j, rand() % (edgeMax - edgeMin) + edgeMin};
            std::vector<long> edge(v, v + 3);
            mGraphData.push_back(edge);
        }
        mIsOccupied[i] = true;
    }
    mNodes = n;
}

Graph::Graph(unsigned maxSize){
    mGraphData.clear();
    mIsOccupied.resize(maxSize);
    mNodes = 0;
    for (unsigned i = 0; i < maxSize; i++)
        mIsOccupied[i] = false;
}

void Graph::AddEdge(unsigned node1, unsigned node2, long cost){
    /*
    C++ compiler on my laptop does not support list initializer for
    vector. Below is a walk - around.
    */
    long v[3] = {node1, node2, cost};
    std::vector<long> edge(v, v + 3);
    AddEdge(edge);
}

void Graph::AddEdge(std::vector<long> &edge){
    mGraphData.push_back(edge);
    AddNode(edge[0]);
    AddNode(edge[1]);
}

void Graph::AddNode(unsigned node){
    if(!mIsOccupied[node]){
        mIsOccupied[node] = true;
        mNodes++;
    }
}

bool Graph::IsContain(unsigned node){
    return mIsOccupied[node];
}

void Graph::Store(std::string fileName, char sep){
    std::ofstream fstream(fileName);
    for (unsigned i = 0; i < mGraphData.size(); i++){
        for (unsigned j = 0; j < mGraphData[i].size(); j++){
            fstream << mGraphData[i][j];
            if (j < mGraphData[i].size() - 1)
                fstream << sep;
        }
        if (i < mGraphData.size() - 1)
            fstream << '\n';
    }
    fstream.close();
}
