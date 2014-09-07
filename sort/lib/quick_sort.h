#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include "sort.h"
#include "my_vector_utilities.h"

class QuickSort :public Sort{
	private:
		std::vector<int> mData;
		unsigned Partition(unsigned ileft, unsigned iright);
		// divide the vector into two group, return the position of the
		// pivot, which is put in the correct position
		void DoQuickSort(unsigned ileft, unsigned iright);
		// sort the vector between [ileft, iright)
		void ChooseRandomPivot(unsigned ileft, unsigned iright);
		// chose a randome element as a pivot at swap it with the first element
	public:
		void AddElement(int x);
		void Sort(void);
		void ToScreen(void);
};

#endif
