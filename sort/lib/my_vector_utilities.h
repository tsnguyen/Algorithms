#ifndef __MY_VECTOR_UTILITIES_H__
#define __MY_VECTOR_UTILITIES_H__

#include <iostream>
#include <vector>

/*
    Output the content of a vecto on screen
*/
template <typename DT>
void VectorToScreen(const std::vector<DT> &vec){
    unsigned i;
    for(i = 0; i < vec.size() - 1; i++)
        std::cout << vec[i] << '\t';
    std::cout << vec[i] << '\n';
}

/*
    Search for the index of the maximum value between i_start (inclusive) and
    i_end (exclusive).
*/
template <typename DT>
unsigned IndexOfMaxElement(    const std::vector<DT> &vec,
                            unsigned i_start,
                            unsigned i_end){
    unsigned i_max = i_start;
    for(unsigned i = i_start; i < i_end; i++)
        if(vec[i] > vec[i_max])
            i_max = i;
    return i_max;
}

/*
    Swapt the elements of vector at i1 and i2
*/
template <typename DT>
void SwapVectorElements(std::vector<DT> &vec, unsigned i1, unsigned i2){
    DT temp;
    temp = vec[i1];
    vec[i1] = vec[i2];
    vec[i2] = temp;
}

/*
    Merge two descending sorted vectors into one. This function
    does not check if the input vectors were sorted, therefore
    it is unsafe. Should never use this function by itself.
*/
template <typename DT>
std::vector<DT> MergeSortedVectors(    const std::vector<DT> &vec1,
                                    const std::vector<DT> &vec2){
    std::vector<DT> merged_vec(vec1.size() + vec2.size());
    for(unsigned i = 0, i1 = 0, i2 = 0; i < merged_vec.size(); i++){
        if (   (i1 < vec1.size())
            && ((i2 >= vec2.size()) ||(vec1[i1] > vec2[i2])) ){
            merged_vec[i] = vec1[i1];
            i1++;
        }
        else{
            merged_vec[i] = vec2[i2];
            i2++;
        }
    }
    return merged_vec;
}

/*
    Sort a vector using merge sort. This is not very efficient because of all the
    value passing.
*/
template <typename DT>
void VectorMergeSort(std::vector<DT> &vec){
    if (vec.size() > 1){
        std::vector<DT> vec1(vec.begin(), vec.begin() + vec.size()/2),
                        vec2(vec.begin() + vec.size()/2, vec.end());
        VectorMergeSort(vec1);
        VectorMergeSort(vec2);
        vec = MergeSortedVectors(vec1, vec2);
    }
}

#endif