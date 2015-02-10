#include "percolation.h"

#include "stdlib.h"
#include "time.h"
#include "iostream"
#include "fstream"

Percolation::Percolation(unsigned N){
    unsigned grid_size = N * N;
    edge_length_ = N;
    grid_.resize(grid_size);
    srand(time(NULL));
    p_uf_ = new UnionFind(grid_size + 2);
    Reset();
}

void Percolation::Reset(void){
    unsigned grid_size = edge_length_ * edge_length_;
    for (unsigned i = 0; i < grid_size; i++)
        grid_[i] = false;
    p_uf_->Reset();
    for (unsigned i = 0; i < edge_length_; i++){
        p_uf_->Union(i, grid_size);
        p_uf_->Union(grid_size - i - 1, grid_size + 1);
    }
}

bool Percolation::IsOpen(unsigned i, unsigned j){
    return grid_[i * edge_length_ + j];
}

unsigned Percolation::Open(unsigned i, unsigned j){
    if (IsOpen(i,j))
        return 0;
    else{
        unsigned index = i * edge_length_ + j;
        grid_[index] = true;
        if ((i > 0) && grid_[index - edge_length_])
            p_uf_->Union(index, index - edge_length_);
        if ((i < edge_length_ - 1) && grid_[index + edge_length_])
            p_uf_->Union(index, index + edge_length_);
        if ((j > 0) && grid_[index - 1])
            p_uf_->Union(index, index - 1);
        if ((j < edge_length_) && grid_[index + 1])
            p_uf_->Union(index, index + 1);
        return 1;
    }
}

bool Percolation::IsPercolate(void){
    return (p_uf_->Find(edge_length_ * edge_length_)
            == p_uf_->Find(edge_length_ * edge_length_ + 1));
}

Percolation::~Percolation(void){
    delete p_uf_;
}

void Percolation::PrintGrid(void){
    for(unsigned i = 0; i< edge_length_; i++){
        for(unsigned j = 0; j < edge_length_; j++)
            std::cout << grid_[i * edge_length_ + j];
        std::cout << '\n';
    }
}
unsigned Percolation::RandomPercolate(void){
    Reset();
    unsigned count = 0, i, j, r, grid_size = edge_length_ * edge_length_;
    while(!IsPercolate()){
        r = rand() % grid_size;
        i = r / edge_length_;
        j = r % edge_length_;
        count += Open(i, j);
    }
    return count;
}
void Percolation::ExportPercolationThreshold(unsigned N,
                                std::string file_name){
    std::ofstream fs(file_name);
    fs << edge_length_ * edge_length_ << '\n';
    for (unsigned i = 0; i < N; i++){
        fs << RandomPercolate();
        if (i < N - 1)
            fs << '\n';
    }
    //PrintGrid();
}
