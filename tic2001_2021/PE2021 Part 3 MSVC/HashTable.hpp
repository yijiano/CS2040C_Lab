#pragma once
#include "HashTable.h"

#ifndef _ASSERT
#define _ASSERT assert
#endif

//Hash function used for this hash table
//x = item to be hashed
//n = no of entries in hash table for modulo
int HashTable::h(int x) {
	//sum of all digits
	int ans = 0;
	while (x > 0) {
		int lastDigit = x % 10;
		ans += lastDigit;
		x /= 10;
	}
	return ans;
}

HashTable::HashTable(int n) {

	//initially, populate has_htable with 0s
	_size = n;
	_nItem = 0;
	_ht = new int[_size];
	for (int i = 0; i < _size; i++) {
		_ht[i] = 0;
	}
}


void HashTable::printHashTable() {
	
	cout << "Current hash table: " << endl;
	for (int i = 0; i < _size; i++) {
		cout << _ht[i] << " ";
	}
	cout << endl;
}


HashTable::~HashTable() {
	delete[] _ht;
}

