#pragma once
#include <iostream>
using namespace std;

template <class T>
class BinarySearchTree;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

template <class T>
class TreeNode {
private:
	T _item;
	TreeNode<T>* _left;
	TreeNode<T>* _right;
	int _height;
	T _sst; // sum of the all the nodes in its subtree with itself as the root
public:
	TreeNode(T x) { _left = _right = NULL; _item = x; _height = 0; _sst = x; };
	friend BinarySearchTree<T>;
};

template <class T>
class BinarySearchTree {
private:
	bool _balancing; 
	// true: the tree will be balanced as an AVL tree mentioned in our lecture
	// false: the tree will not do any rotation to balance itself

	int _size;
	TreeNode<T>* _root;
	void _printTree(int indent, TreeNode<T>*, bool withSST);
	void _preOrderPrint(TreeNode<T>*);
	void _inOrderPrint(TreeNode<T>*);
	void _postOrderPrint(TreeNode<T>*);
	TreeNode<T>* _insert(TreeNode<T>* current, T x);
    void _destroySubTree(TreeNode<T>*);
	int _insert_update_height(TreeNode<T>* current);
	TreeNode<T>* _insert_right_rotate(TreeNode<T>* target);
	TreeNode<T>* _insert_left_rotate(TreeNode<T>* target);
	int _insert_get_balance(TreeNode<T>* node);



public:
	BinarySearchTree(bool balancing=true) { _root = NULL; _size = 0; _balancing = balancing; }
	~BinarySearchTree();
	int size() { return _size; };
	void insert(T);
	void printTree(bool withSST = true); 
	// if withSST==true, it will print the sum of subtree also

	void inOrderPrint();
	void postOrderPrint();
	void preOrderPrint();

	T sumLE(T n);

	
};


// Returns updated node height
template <typename T> 
int BinarySearchTree<T>::_insert_update_height(TreeNode<T>* current) {
	int left_height = current->_left ? current->_left->_height : -1;
	int right_height = current->_right ? current->_right->_height : -1;
	return MAX(left_height, right_height) + 1;
}

// Right rotation for balancing
template <typename T> 
TreeNode<T>* BinarySearchTree<T>::_insert_right_rotate(TreeNode<T>* target) {
	TreeNode<T>* pivot = target->_left;
	TreeNode<T>* subtree = pivot->_right;

	pivot->_right = target;
	target->_left = subtree;

	target->_height = _insert_update_height(target);
	pivot->_height = _insert_update_height(pivot);

	return pivot;
}

// Left rotation for balancing
template <typename T> 
TreeNode<T>* BinarySearchTree<T>::_insert_left_rotate(TreeNode<T>* target) {
	TreeNode<T>* pivot = target->_right;
	TreeNode<T>* subtree = pivot->_left;

	pivot->_left = target;
	target->_right = subtree;

	target->_height = _insert_update_height(target);
	pivot->_height = _insert_update_height(pivot);

	return pivot;
}

// Returns balance factor of a node
template <typename T> 
int BinarySearchTree<T>::_insert_get_balance(TreeNode<T>* node) {
	if (node == nullptr) return 0;
	int left_height = node->_left ? _insert_update_height(node->_left) : -1;
	int right_height = node->_right ? _insert_update_height(node->_right) : -1;
	return left_height - right_height;
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_insert(TreeNode<T>* current, T x) {

	if (current->_item > x)
	{
		if (current->_left)
			current->_left = _insert(current->_left, x);
		else
		{
			current->_left = new TreeNode<T>(x);
			_size++;
		}
	}
	else if (x > current->_item) {
		if (current->_right)
			current->_right = _insert(current->_right, x);
		else
		{
			current->_right = new TreeNode<T>(x);
			_size++;
		}
	}
	else
		return current;


	if (_balancing) {
		current->_height = _insert_update_height(current);
		int balance = _insert_get_balance(current);

		// Left Left Case
		if (balance > 1 && x < current->_left->_item) {
			return _insert_right_rotate(current);
		}

		// Right Right Case
		if (balance < -1 && x > current->_right->_item) {
			return _insert_left_rotate(current);
		}

		// Left Right Case
		if (balance > 1 && x > current->_left->_item) {
			current->_left = _insert_left_rotate(current->_left);
			return _insert_right_rotate(current);
		}
		// Right Left Case
		if (balance < -1 && x < current->_right->_item) {
			current->_right = _insert_right_rotate(current->_right);
			return _insert_left_rotate(current);
		}
	}
	if (_left != nullptr && _right != nullptr) _ssl = _item;
	else if (_left != nullptr) _ssl += _left->_ssl;
	else if (_right != nullptr) _ssl += _right->_ssl;

	return current;

}

template <class T>
void BinarySearchTree<T>::insert(T x) {

	if (_root == NULL)
	{
		_root = new TreeNode<T>(x);
		_size++;
	}
	else
		_root = _insert(_root, x);

}




template <class T>
void BinarySearchTree<T>::printTree(bool withHeight) {
	_printTree(0, _root, withHeight);
}

template <class T>
T BinarySearchTree<T>::sumLE(T n)
{
	TreeNode* current = _root;
	
}



template <class T>
void BinarySearchTree<T>::_preOrderPrint(TreeNode<T>* node) {
	if (!node) return;
	cout << node->_item << "(" << node->_sst << ") ";
	_preOrderPrint(node->_left);
	_preOrderPrint(node->_right);
}

template <class T>
void BinarySearchTree<T>::preOrderPrint() {
	_preOrderPrint(_root);
	cout << endl;
}


template <class T>
void BinarySearchTree<T>::postOrderPrint() {

}



template <class T>
void BinarySearchTree<T>::_postOrderPrint(TreeNode<T>* node) {

}

template <class T>
void BinarySearchTree<T>::inOrderPrint() {

}


template <class T>
void BinarySearchTree<T>::_inOrderPrint(TreeNode<T>* node) {

}
template <class T>
void BinarySearchTree<T>::_printTree(int indent, TreeNode<T>* node, bool withSST) {

	if (!node)
		return;

	if (node->_right)
		_printTree(indent + 2, node->_right, withSST);
	for (int i = 0; i < indent; i++)
		cout << "  ";
	cout << node->_item;
	if (withSST)
		cout <<  "(s=" << node->_sst << ")";
	cout << endl;
	if (node->_left)
		_printTree(indent + 2, node->_left, withSST);


};


template <class T>
void BinarySearchTree<T> ::_destroySubTree(TreeNode<T>* node)
{
	if (node->_left)
		_destroySubTree(node->_left);
	if (node->_right)
		_destroySubTree(node->_right);
	delete node;
}

template <class T>
BinarySearchTree<T> :: ~BinarySearchTree()
{
	
	if (_root)
		_destroySubTree(_root);
}



class MagicalPancakeGym {
public:
	void addPancake(long long int weight);
	long long int minimalBottomPancake2Lift(long long int totalW);
	void printPancakes();
	long long int totalWeightAbovePancake(long long int w);
};

long long int MagicalPancakeGym::totalWeightAbovePancake(long long int w)
{
	return 0;
}

void MagicalPancakeGym::addPancake(long long int weight)
{

}

void MagicalPancakeGym::printPancakes()
{

}

long long int MagicalPancakeGym::minimalBottomPancake2Lift(long long int totalW)
{
	return 0;
}

