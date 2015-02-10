#ifndef __SELECTION_SORT_H__
#define __SELECTION_SORT_H__
#include "sort.h"
#include "my_vector_utilities.h"
class SelectionSort :public Sort{
    private:
        std::vector<int> mData;
    public:
        void AddElement(int x);
        void ToScreen(void);
        void Sort(void);
};

#endif