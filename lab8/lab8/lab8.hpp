#pragma once
#include <exception>

struct OutOfBounds : public std::exception {
	const char * what() const throw () {
		return "out of bounds chris why..";
	}
};

template<class T, size_t n>
class FixedList
{
public:
	FixedList() {
		arrayList = new T[n];
		max = n;
		currentSize = 0;
	}
	~FixedList() {
		delete(arrayList);
	}

	const T& get(unsigned int index) const {
		return arrayList[index];
	}

	T& operator[] (unsigned int index) {
		if (index >= currentSize) {
			throw OutOfBounds();
		}
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
			return NULL;
		}
		T temp = arrayList[index];
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