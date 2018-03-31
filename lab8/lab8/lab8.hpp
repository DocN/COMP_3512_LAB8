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


	bool add(const T& t) {
		if (currentSize == max) {
			return false;
		}
		arrayList[currentSize] = t;
		currentSize++;
		return true;
	}

	T remove(const T& t) {
		int index = getFirstIndex(t);
		if (index == -1) {
			return nullptr;
		}
		T temp = arrayList[i];
		for (int i = index; i < max; i++) {
			arrayList[i] = arrayList[i + 1];
		}
		currentSize--;
		return temp;
	}

private:
	T * arrayList;
	size_t max;
	size_t currentSize;

};