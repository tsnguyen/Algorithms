#include "quick_sort.h"
#include "stdlib.h"

void QuickSort::AddElement(int x){
	mData.push_back(x);
}

void QuickSort::ToScreen(void){
	VectorToScreen(mData);
}

unsigned QuickSort::Partition(unsigned ileft, unsigned iright){
	ChooseRandomPivot(ileft, iright);
	int pivot = mData[ileft];
	unsigned boundary, i;
	for (boundary = ileft + 1, i = ileft + 1; i < iright; i++)
		if(mData[i] > pivot){
			SwapVectorElements(mData, i, boundary);
			boundary ++;
		}
	SwapVectorElements(mData, ileft, boundary - 1);
	return boundary - 1;
}

void QuickSort::DoQuickSort(unsigned ileft, unsigned iright){
	if (iright - ileft > 1){
		unsigned imid = Partition(ileft, iright);
		DoQuickSort(ileft, imid);
		DoQuickSort(imid + 1, iright);
	}
}

void QuickSort::Sort(void){
	DoQuickSort(0, mData.size());
}

void QuickSort::ChooseRandomPivot(unsigned ileft, unsigned iright){
	if(iright - ileft >1){
		unsigned delta_i = rand() % (iright - ileft);
		SwapVectorElements(mData, ileft, ileft + delta_i);
	}
}