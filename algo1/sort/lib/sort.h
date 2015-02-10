#ifndef __SORT_H__
#define __SORT_H__

#include "iostream"

class Sort{
	public:
		virtual void AddElement(int x) = 0;
		virtual void ToScreen(void) = 0;
};

#endif