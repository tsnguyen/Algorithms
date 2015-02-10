#include "union_find.h"
#include "iostream"

UnionFind::UnionFind(unsigned SIZE){
    id_.resize(SIZE);
    weight_.resize(SIZE);
    Reset();
}
void UnionFind::Reset(void){
    for(unsigned i = 0; i < id_.size(); i++){
        id_[i] = i;
        weight_[i] = 1;
    }
}

unsigned UnionFind::Find(unsigned i){
    while(id_[i] != i){
        id_[i] = id_[id_[i]];
        i = id_[i];
    }
    return i;
}

void UnionFind::Union(unsigned i, unsigned j){
    unsigned root_i = Find(i), root_j = Find(j);
    if(root_i != root_j){
        if(weight_[root_i] < weight_[root_j]){
            weight_[root_j] += weight_[root_i];
            id_[root_i] = root_j;
        }
        else{
            weight_[root_i] += weight_[root_j];
            id_[root_j] = root_i;
        }
    }
}

void UnionFind::PrintID(void){
    for(unsigned i = 0; i < id_.size(); i++)
        std::cout << id_[i] << ' ';
    std::cout << '\n';
}
