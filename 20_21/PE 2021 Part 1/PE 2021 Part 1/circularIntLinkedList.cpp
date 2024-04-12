#include <iostream>
#include "circularIntLinkedList.h"
using namespace std;

ListNode::ListNode(int n)
{
	_item = n;
	_next = NULL;
}


////////////////////////////////////////////////////////////////////////////
//      You should ONLY modify the bodies of the following functions      //
// You should copy and paste ALL the functions below onto coursemology    //
////////////////////////////////////////////////////////////////////////////

void CircularList::advanceHead()
{
	if (_head != nullptr) {
		_head = _head->_next; // Move head to next node
	}
}

void CircularList::insertHead(int n)
{
	ListNode* new_node = new ListNode(n);
	if (_head == nullptr) {
		_head = new_node;
		_head->_next = _head; // Point to itself, maintaining circularity
	}
	else {
		new_node->_next = _head->_next;
		_head->_next = new_node;
		std::swap(_head->_item, new_node->_item); // Swap values to avoid updating last node
	}
	_size++;
};

void CircularList::removeHead()
{
	if (_head == nullptr) {
		throw std::out_of_range("Cannot remove from an empty list.");
	}
	if (_size == 1) {
		delete _head;
		_head = nullptr;
	}
	else {
		ListNode* old_head = _head;
		ListNode* current = _head;
		while (current->_next != _head) {
			current = current->_next;
		}
		_head = _head->_next;
		current->_next = _head;
		delete old_head;
	}
	_size--;
}

void CircularList::print() 
{
	if (_head == nullptr) return;
	ListNode* start = _head;
	do {
		cout << start->_item << " ";
		start = start->_next;
	} while (start != _head);
	cout << endl;
}

bool CircularList::exist(int n) 
{
	if (_head == nullptr) return false;
	ListNode* start = _head;
	do {
		if (start->_item == n) return true;
		start = start->_next;
	} while (start != _head);
	return false;
}

int CircularList::headItem()
{
	if (!_head) throw std::out_of_range("Empty list has no head item.");
	return _head->_item;
}

CircularList::~CircularList()
{
	while (_size > 0) {
		removeHead();
	}
};

