#pragma once
#include <exception>

template<class T, size_t n>
class FixedList
{
public:
	FixedList() {
		arrayList = new T[n];
		max = n;
		currentSize = 0;
	}
	~FixedListed() {
		delete arrayList;
	}



private:
	T * arrayList;
	size_t max;
	size_t currentSize;

};