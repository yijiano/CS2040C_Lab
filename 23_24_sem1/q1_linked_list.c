#include <iostream>
using namespace std;
#pragma once
class ListNode
{
private:
	int _item;
	ListNode* _next;
public:
	ListNode(int);
	int content() { return _item; };
	friend class List;
};
class List
{
private:
	int _size;
	ListNode* _head;
	ListNode* _mid;
	ListNode* _tail;
public:
	List()
	{
		_size = 0;
		_head = NULL;
		_mid = NULL;
		_tail = NULL;
	};
	~List();
	void insertTail(int);
	void removeHead();
	void print();
	int headItem();
	int midItem();
};
ListNode::ListNode(int n)
{
	_item = n;
	_next = NULL;
}
void List::insertTail(int n)
{
	if (_size == 0)
	{
		ListNode* newNode = new ListNode(n);
		newNode->_next = NULL;
		_head = newNode;
		_mid = newNode;
		_tail = newNode;
		_size++;
		return;
	}
	ListNode* newNode = new ListNode(n);
	_tail->_next = newNode;
	_tail = newNode;
	newNode->_next = NULL;
	_size++;
	if (_size % 2 != 0 && _size > 2)
	{
		_mid = _mid->_next;
	}
	return;
};
// must work
void List::removeHead()
{
	if (_size > 0) {
		ListNode *temp = _head;
		_head = _head->_next;
		if (_size == 2)
		{
			_mid = _mid->_next;
		}
		delete temp;
		_size--;
		if (_size % 2 != 0 && _size > 1)
		{
			_mid = _mid->_next;
		}
	}
	
}
void List::print() {
	ListNode* ptr = _head;
	while (ptr) {
		cout << ptr->_item << " ";
		ptr = ptr->_next;
	}
	cout << endl;
}
int List::midItem() {
	return _mid->_item;
}
// must work
int List::headItem()
{
	return _head->_item;
}
List::~List()
{
	while (_size != 0)
		removeHead();
};
int part1Test()
{
	List l;
	for (int i = 0; i < 10; i++)
	{
		l.insertTail(i * 2 + 1);
		cout << "List: ";
		l.print();
		cout << "Mid = " << l.midItem() << endl << endl;
	}
	cout << endl << "Remove Head" << endl;
	for (int i = 0; i < 9; i++)
	{
		l.removeHead();
		cout << "List: ";
		l.print();
		cout << "Mid = " << l.midItem() << endl << endl;
	}
	cout << endl << "Composite" << endl;
	for (int i = 1; i < 9; i++)
	{
		l.insertTail(i * 10 + 1);
		l.insertTail(i*10);
		cout << "List: ";
		l.print();
		cout << "Mid = " << l.midItem() << endl << endl;
		l.removeHead();
		cout << "List: ";
		l.print();
		cout << "Mid = " << l.midItem() << endl << endl;
	}
	
	return 0;
}