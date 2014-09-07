#include "selection_sort.h"

void SelectionSort::AddElement(int x){
    mData.push_back(x);
}

void SelectionSort::ToScreen(void){
    VectorToScreen(mData);
}

void SelectionSort::Sort(void){
    unsigned i_max;
    for (unsigned i = 0; i < mData.size(); i++){
        i_max = IndexOfMaxElement(mData, i, mData.size());
        if (i != i_max)
            SwapVectorElements(mData, i, i_max);
    }
}
