#include "merge_sort_naive.h"

void MergeSortNaive::ToScreen(void){
    VectorToScreen(mData);
}
void MergeSortNaive::AddElement(int x){
    mData.push_back(x);
}
void MergeSortNaive::Sort(void){
    VectorMergeSort(mData);
}