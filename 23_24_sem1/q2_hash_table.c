#include <iostream>
using namespace std;
#define HT_DEFAULT_SIZE 8
#define HT_MIN_SIZE 8
#define INSERT_STR "Inserting "
#define REMOVE_STR "Removing " 
#define COL_STR "Collision at index "
#define RESIZE_STR "Resizing to "
class HashTable {
private:
	int* _ht; //array to store hash table items. Max 100
	int _size; //size of the hash table
	int _nItem; //no. of items added
	void _resize(int newSize);
public:
	HashTable();
	void insert(int);
	void remove(int);
	bool exist(int);
	int tableSize() { return _size; };
	int numItems() { return _nItem; };
	void printHashTable();
	~HashTable();
};
//Hash function used for this hash table
//x = item to be hashed
//n = no of entries in hash table for modulo
int h(int x) {
	//sum of all digits
	int ans = 0;
	while (x > 0) {
		int lastDigit = x % 10;
		ans += lastDigit;
		x /= 10;
	}
	return ans;
}
HashTable::HashTable() {
	//initially, populate has_htable with 0s
	_size = HT_DEFAULT_SIZE;
	_nItem = 0;
	_ht = new int[_size];
	for (int i = 0; i < _size; i++) {
		_ht[i] = 0;
	}
}
void HashTable::insert(int n) {
	cout << INSERT_STR << n << endl;
	//find the first available spot
	int idx = h(n) % _size;
	int initial = idx;
	int j = 1;
	while (true)
	{
		if (_ht[idx] == -1 || _ht[idx] == 0)
		{
			_ht[idx] = n;
			_nItem++;
			if (_nItem > floor(_size / 2))
			{
				_resize(2 * _size);
			}
			return;
		}
		cout << COL_STR << idx << endl;
		idx = (initial + j) % _size;
		j++;
	}
	
}
//n does not necasarrily exist in the hash table
void HashTable::remove(int n) {
	cout << REMOVE_STR << n << endl;
	int idx = h(n) % _size;
	int initial = idx;
	int j = 1;
	if (!exist(n))
	{
		cout << "Fail to remove " << n << endl;
		return;
	}
	while (true)
	{
		if (_ht[idx] == 0)
		{
			cout << "Fail to remove " << n << endl;
			return;
		}
		if (_ht[idx] == n)
		{
			_ht[idx] = -1;
			_nItem--;
			if (_nItem < floor(_size / 4) && (_size/2 >= 8))
			{
				_resize(_size / 2);
			}
			return;
		}
		idx = (initial + j) % _size;
		j++;
	}
}
bool HashTable::exist(int n) {
	int idx = h(n) % _size;
	int initial = idx;
	int j = 1;
	while (true) {
		if (_ht[idx] == 0) {
			return false;
		}
		if (_ht[idx] == n) {
			return true;
		}
		idx = (initial + j) % _size;
		j++;
	}
}
void HashTable::printHashTable() {
	for (int i = 0; i < _size; i++)
		cout << _ht[i] << " ";
	cout << endl;
}
 void HashTable::_resize(int newSize) {
	 cout << RESIZE_STR << newSize << endl;
	 int* temp = _ht;
	 int oldSize = _size;
	 _ht = new int[newSize];
	 for (int i = 0; i < newSize; i++) {
		 _ht[i] = 0;
	 }
	 _size = newSize;
	 _nItem = 0;
	 //Redo the inserting
	 for (int i = 0; i < oldSize; i++) {
		 if (temp[i] > 0) {
			 insert(temp[i]);
		 }
	 }
}
HashTable::~HashTable() {
	delete[] _ht;
}
void hastTabletest2() {
	HashTable ht;
	int n = 1;
	for (int i = 1; i < 7; i++)
	{
		ht.insert(n);
		cout << "The new hash table: ";
		ht.printHashTable();
		n = n * 10;
		cout << endl;
	}
	n = 1;
	for (int i = 1; i < 7; i++)
	{
		ht.remove(n);
		cout << "The new hash table: ";
		ht.printHashTable();
		n = n * 10;
		cout << endl;
	}
}
void hastTabletest1() {
	HashTable ht;
	int n = 1;
	for (int i = 1; i < 7; i++)
	{
		ht.insert(n);
		cout << "The new hash table: ";
		ht.printHashTable();
		n = n * 2;
		cout << endl;
	}
	n = 1;
	for (int i = 1; i < 7; i++)
	{
		ht.remove(n);
		cout << "The new hash table: ";
		ht.printHashTable();
		n = n * 2;
		cout << endl;
	}
}
