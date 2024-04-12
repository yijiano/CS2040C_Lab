#pragma once
#define DEFAULTHEAPSIZE 1023
template <class T>
class DHeap {
protected:
	T* _heap;
    int _d; // It is a d-ary Heap
	int _n; // no. item in the heap
	void _bubbleUp(int index);
	void _bubbleDown(int index);
    int _lookFor(T x); // return the index of the item x, return -1 if not found
                       // it is not a good/usual implementation, so we hide it from public
public:
	DHeap(int d) {
        _d = d;
		_heap = new T[DEFAULTHEAPSIZE];
		_n = 0;
	};

	void insert(T);
    bool empty() {return _n==0;};
	T extractMax();
    T peekMax() {return _heap[0];};
	void printHeapArray();
    

	~DHeap() { delete[] _heap; };
};

#include "dheap.hpp"
