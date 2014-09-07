#include "merge_sort.h"

void MergeSort::AddElement(int x){
    mData.push_back(x);
}

void MergeSort::Sort(void){
    DoMergeSort(0, mData.size());
}

void MergeSort::ToScreen(void){
    VectorToScreen(mData);
}

void MergeSort::Merge(unsigned istart, unsigned imid, unsigned iend){
    std::vector<int>    vec1(mData.begin() + istart, mData.begin() + imid),
                        vec2(mData.begin() + imid, mData.begin() + iend);
    for(unsigned i = istart, i1 = 0, i2 = 0; i < iend; i++){
        if (   (i1 < vec1.size())
            && ((i2 >= vec2.size()) ||    (vec1[i1] > vec2[i2])) ){
            mData[i] = vec1[i1];
            i1++;
        }
        else{
            mData[i] = vec2[i2];
            i2++;
        }
    }
}

void MergeSort::DoMergeSort(unsigned istart, unsigned iend){
    if(iend - istart > 1){
        unsigned imid = (istart + iend) / 2;
        DoMergeSort(istart, imid);
        DoMergeSort(imid, iend);
        Merge(istart, imid, iend);
    }
}