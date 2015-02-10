#include "unionfind.h"

UnionFind::UnionFind(unsigned size){
    /*
    Construct the matrix data with no connection. Each node is its own leader
    and is an isolated cluster of size 1.
    */
    for(unsigned i = 0; i < size; i++){
        std::vector<unsigned> row;
        row.resize(2);
        row[0] = i;
        row[1] = 1;
        mUFData.push_back(row);
    }
}
unsigned UnionFind::Find(unsigned i){
    /*
    Find the leader of a node by going up the tree until reaching the root.
    */
    unsigned leader = i, follower = i;
    do{
        follower = leader;
        leader = mUFData[follower][0];
    }while(leader != follower);
    return leader;
}
unsigned UnionFind::Union(unsigned i1, unsigned i2){
    /*
    Union two nodes i1 and i2: if they have the same leader, they are already
    in the same cluster, do nothing and return the cluster size. If i1 and i2
    have different leader, update the leader of the smaller cluster to point
    to the leader of the bigger cluster, update the size of the merged cluster
    and return the total size.
    */
    unsigned leader1, leader2, clusterSize;
    leader1 = Find(i1);
    leader2 = Find(i2);
    if (leader1 != leader2){
        clusterSize = mUFData[leader2][1] + mUFData[leader1][1];
        if (mUFData[leader1][1] < mUFData[leader2][1]){
            mUFData[leader1][0] = leader2;
            mUFData[leader2][1] = clusterSize;
        }
        else{
            mUFData[leader2][0] = leader1;
            mUFData[leader1][1] = clusterSize;
        }
    }
    else
        clusterSize = mUFData[leader1][1];
    return clusterSize;
}
