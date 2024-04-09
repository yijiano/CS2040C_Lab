#pragma once
#include <math.h>

#include <iostream>
using namespace std;

#ifndef HEAPHPP
#define HEAPHPP

#define DEFAULTHEAPSIZE 1023

template <class T>
class Heap {
  protected:
    T* _heap; 
    int _lastIndex;

  public:
    Heap(): _heap(new T[DEFAULTHEAPSIZE]), _lastIndex(-1){};

    int size() const {
      return _lastIndex + 1;
    }

    bool empty() const {
      return _lastIndex == -1;
    }

    bool isFull() const {
      return _lastIndex == DEFAULTHEAPSIZE;
    }

    void insert(const T&);
    T extractMax();
    T peekMax() const;
    void printHeapArray() const;
    void printTree() const;
    void changeKey(const T& from, const T& to);
    void deleteItem(const T&);

    ~Heap() { delete[] _heap; };

  private:
    int leftChildIndex(const int parentIndex) const {
      int leftChild = 2 * parentIndex + 1;
      if (leftChild > _lastIndex) return -1; // No left child.
      return leftChild;
    }

    int rightChildIndex(const int parentIndex) const {
      int rightChild = 2 * parentIndex + 2;
      if (rightChild > _lastIndex) return -1; // No right child.
      return rightChild;
    }

    int biggestChildIndex(const int parentIndex) const {
      int left = leftChildIndex(parentIndex);
      int right = rightChildIndex(parentIndex);
      // If there is no left child, there must be no right child due to heap property
      if (right == -1) {
      // There is no right child.
        if (left == -1) return -1; // No children
        else return left; //There is no right child but there is a left child
      }
      // There are two children
      return _heap[left] > _heap[right] ? left : right;
    }

    int parentIndex(const int childIndex) const {
      if (childIndex == 0) return -1; // Child is head of heap.
      return (childIndex - 1) / 2;
    }

    void bubbleUp(const int index);
    void bubbleDown(const int index);
    void bubble(const int index);
    int searchIndex(const T& item);
};

template <class T>
void Heap<T>::bubbleUp(const int index) {
  int currentIndex = index;
  while (parentIndex(currentIndex) != -1) {
    int parent = parentIndex(currentIndex);
    if (_heap[currentIndex] > _heap[parent]) {
      swap(_heap[currentIndex], _heap[parent]);
    }
    currentIndex = parent;
  }
}

template <class T>
void Heap<T>::bubbleDown(const int index) {
  int currentIndex = index;
  while (currentIndex != _lastIndex) {
    int biggerChild = biggestChildIndex(currentIndex);
    if (biggerChild == -1) return; // No child therefore cannot bubbleDown
    if (_heap[biggerChild] > _heap[currentIndex]) {
      swap(_heap[currentIndex], _heap[biggerChild]);
      currentIndex = biggerChild;
    }
    else return;
  }
}

template <class T>
void Heap<T>::bubble(const int itemIndex) {
  if (parentIndex(itemIndex) != -1 && _heap[itemIndex] > _heap[parentIndex(itemIndex)]) {
    bubbleUp(itemIndex);
  }
  else if (biggestChildIndex(itemIndex) != -1 && _heap[biggestChildIndex(itemIndex)] > _heap[itemIndex]) {
    bubbleDown(itemIndex);
  } 
}

template <class T>
void Heap<T>::insert(const T& item) {
  if (isFull()) throw std::out_of_range("Heap is full");
  ++_lastIndex;
  _heap[_lastIndex] = item;
  bubble(_lastIndex);
}

template <class T>
T Heap<T>::extractMax() {
  if (empty()) throw std::out_of_range("Heap is empty");
  //_lastIndex >= 0
  T max = _heap[0];
  if (_lastIndex != 0) swap(_heap[0], _heap[_lastIndex]);
  --_lastIndex;
  if (_lastIndex > 0) bubble(0);
  return max;
}

template <class T>
T Heap<T>::peekMax() const {
  if (empty()) throw std::out_of_range("Heap is empty");
  return _heap[0];
};

template <class T>
void Heap<T>::printHeapArray() const {
  for (int i = 0; i < size(); i++) {
    cout << _heap[i] << " ";
  }
  cout << endl;
}

template <class T>
int Heap<T>::searchIndex(const T& item) {
  for (int i = 0; i < size(); i++) {
    if (!(_heap[i] > item) && !(item > _heap[i])) return i;
  }
  return -1; // Item is not in heap
}

template <class T>
void Heap<T>::changeKey(const T& from, const T& to) {
  if (empty()) throw std::out_of_range("Heap is empty");
  
  int itemIndex = searchIndex(from);
  if (itemIndex == -1) throw std::out_of_range("key not in heap");
  _heap[itemIndex] = to;
  bubble(itemIndex);
}

template <class T>
void Heap<T>::deleteItem(const T& x) {
  if (empty()) throw std::out_of_range("Heap is empty");
  
  int itemIndex = searchIndex(x);
  if (itemIndex == -1) throw std::out_of_range("key not in heap");

  if (_lastIndex != 0) swap(_heap[itemIndex], _heap[_lastIndex]);
  --_lastIndex;
  bubble(itemIndex);
}

template <class T>
void Heap<T>::printTree() const {
  int parity = 0;
  if (size() == 0) return;
  int space = pow(2, 1 + (int)log2f(size())), i;
  int nLevel = (int)log2f(size()) + 1;
  int index = 0, endIndex;
  int tempIndex;

  for (int l = 0; l < nLevel; l++) {
    index = 1;
    parity = 0;
    for (i = 0; i < l; i++) index *= 2;
    endIndex = index * 2 - 1;
    index--;
    tempIndex = index;
    while (index < size() && index < endIndex) {
      for (i = 0; i < space - 1; i++) cout << " ";
      if (index == 0)
        cout << "|";
      else if (parity)
        cout << "\\";
      else
        cout << "/";
      parity = !parity;
      for (i = 0; i < space; i++) cout << " ";
      index++;
    }
    cout << endl;
    index = tempIndex;
    while (index < size() && index < endIndex) {
      for (i = 0; i < (space - 1 - ((int)log10(_heap[index]))); i++)
        cout << " ";
      cout << _heap[index];
      for (i = 0; i < space; i++) cout << " ";
      index++;
    }

    cout << endl;
    space /= 2;
  }
}

#endif