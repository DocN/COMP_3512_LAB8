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

	const T& get(unsigned int index) const {
		return arrayList[index];
	}

	T& operator[] (usigned int index) {
		return arrayList[index];
	}
	int getFirstIndex(const T& t) const {
		for (int i = 0; i < currentSize; i++) {
			if (arrayList[i] == t) {
				return i;
			}
		}
		return -1;
	}

	size_t size() const {
		return currentSize;
	}

	size_t capacity() const {
		return max;
	}




private:
	T * arrayList;
	size_t max;
	size_t currentSize;

};