#pragma once
#include <iostream>
using namespace std;

template <class T>
class BinarySearchTree;

template <class T>
class TreeNode {
private:
	T _item;
	TreeNode<T>* _left;
	TreeNode<T>* _right;
	int _height;
public:
	TreeNode(T x) { _left = _right = NULL; _item = x; _height = 0; };

	friend BinarySearchTree<T>;
};

template <class T>
class BinarySearchTree {
protected:
	int _size;
	TreeNode<T>* _root;
	void _printTree(int indent, TreeNode<T>*, bool withHeight);

	// The following functions are optional for you to implement. 
	TreeNode<T>*  _insert(TreeNode<T>* current, T x);
	void _inOrderPrint(TreeNode<T>* node);
	void _postOrderPrint(TreeNode<T>* node);
	void _preOrderPrint(TreeNode<T>* node);
	TreeNode<T>* _rightRotation(TreeNode<T>*);
	TreeNode<T>* _leftRotation(TreeNode<T>*);
	TreeNode<T>* _searchMax(TreeNode<T>*);
	TreeNode<T>* _searchMin(TreeNode<T>*);
	TreeNode<T>* _search(TreeNode<T>*, T);
	void _destroySubTree(TreeNode<T>*);
    void update(TreeNode<T>* node);
    void updatetree(TreeNode<T>* node);
    TreeNode<T>* parent(T x);
    TreeNode<T>* rotate(TreeNode<T>* node);
    int isBalanced(TreeNode<T>* node);



public:
	BinarySearchTree() { _root = NULL; _size = 0; }
	~BinarySearchTree();
	int size() { return _size; };
	void insert(T);
	void printTree(bool withHeight = 1);
	void inOrderPrint();
	void postOrderPrint();
	void preOrderPrint();
	T searchMax() { return _searchMax(_root)->_item; };
	T searchMin() { return _searchMin(_root)->_item; };
	bool exist(T x) { return _search(_root, x); };
	T search(T x) { return T(); };
	T successor(T);

};



template <class T>
void BinarySearchTree<T>::insert(T x)
{
	_root = _root ? _insert(_root, x) : new TreeNode<T>(x);
	if (_size == 0) _size++;
}

template <class T>
void BinarySearchTree<T>::_printTree(int indent, TreeNode<T>* node, bool withHeight) {

	if (!node)
		return;

	if (node->_right)
		_printTree(indent + 2, node->_right, withHeight);
	for (int i = 0; i < indent; i++)
		cout << "  ";
	cout << node->_item;
	if (withHeight)
		cout << "(h=" << node->_height << ")";
	cout << endl;
	if (node->_left)
		_printTree(indent + 2, node->_left, withHeight);


};

template <class T>
void BinarySearchTree<T>::printTree(bool withHeight) {
	_printTree(0, _root, withHeight);
}


template <class T>
void BinarySearchTree<T>::preOrderPrint() {

	_preOrderPrint(_root);
	cout << "\n";
}


template <class T>
void BinarySearchTree<T>::_preOrderPrint(TreeNode<T>* node) {
	if (!node) return;
	cout << node->_item << " ";
	_preOrderPrint(node->_left);
	_preOrderPrint(node->_right);
}


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



template <class T>
void BinarySearchTree<T>::inOrderPrint() {
    _inOrderPrint(_root);
    cout << "\n";
    return;
}


template <class T>
void BinarySearchTree<T>::_inOrderPrint(TreeNode<T>* node) {
    if(node == NULL) {
        return;
    }
    _inOrderPrint(node->_left);
    cout << node->_item << " ";
    _inOrderPrint(node->_right);
    return;
}


template <class T>
void BinarySearchTree<T>::postOrderPrint() {
    _postOrderPrint(_root);
    cout << "\n";
    return;
}


template <class T>
void BinarySearchTree<T>::_postOrderPrint(TreeNode<T>* node) {
    if(node == NULL) {
        return;
    }
    _postOrderPrint(node->_left);
    _postOrderPrint(node->_right);
    cout << node->_item << " ";
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_insert(TreeNode<T>* current, T x) {
    if (current->_item > x)
    {
        if (current->_left) {
            current->_left = _insert(current->_left, x);
            update(current);
            current = rotate(current);
            update(current);
        }
        else
        {
            current->_left = new TreeNode<T>(x);
            _size++;
            update(current);

        }
    }
    else if (x > current->_item) {
        if (current->_right) {
            current->_right = _insert(current->_right, x);
            update(current);
            current = rotate(current);
            update(current);

        }
        else
        {
            current->_right = new TreeNode<T>(x);
            _size++;
            update(current);

        }
    }
    else
        return current; // When the node already existed in the tree

    return current;

}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_searchMax(TreeNode<T>* current) {
    while(current->_right) {
        current = current->_right;
    }
    return current;
}


template <class T>
TreeNode<T>* BinarySearchTree<T>::_searchMin(TreeNode<T>* current) {
    while(current->_left) {
        current = current->_left;
    }
    return current;
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_search(TreeNode<T>* current, T x) {
    if (current == NULL) {
        return NULL;
    }
    if (x == current->_item) {
        return current;
    }
    else if (current->_item > x) {
        return _search(current->_left, x);
    }
    else {
        return _search(current->_right, x);
    }
}



template <class T>
T BinarySearchTree<T>::successor(T x)
{
	TreeNode<T>* temp = _root;
    TreeNode<T>* temp1 = NULL;
    if (x >= searchMax()) {
        cout << "no successor" << "\n";
        return x;
    }
    if(exist(x)){
        if(_search(_root, x)->_right) {
            return _searchMin(_search(_root, x)->_right)->_item;
        }
    }
    while(temp) {
        if(temp->_item > x) {
            temp1 = temp;
            temp = temp->_left;
        }
        else {
            temp = temp->_right;
        }
    }
    return temp1->_item;
   
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_leftRotation(TreeNode<T>* node)
{
    if (!exist(node->_item)){
        return NULL;
    }
    TreeNode<T>* temp = parent(node->_item);

    TreeNode<T>* temp1 = node->_right;
    temp = temp1;
    node->_right = temp1->_left;
    temp1->_left = node;
    update(node);
    update(temp);
    return temp;
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_rightRotation(TreeNode<T>* node)
{
    if (!exist(node->_item)){
        return NULL;
    }
    TreeNode<T>* temp = parent(node->_item);

    TreeNode<T>* temp1 = node->_left;
    temp = temp1;
    node->_left = temp1->_right;
    temp1->_right = node;
    update(node);
    update(temp);
    return temp;
}

template <class T>
void BinarySearchTree<T>::update(TreeNode<T>* node)
{
    if (node->_left == NULL && node->_right == NULL) {//no children
        node->_height = 0;
        return;
    }
    else if (node->_left != NULL && node->_right != NULL) { // 2 children
        node->_height = max(node->_left->_height, node->_right->_height) + 1;
        return;
    }
    else if (node->_left == NULL) { // only right child
        node->_height = node->_right->_height + 1;
        return;
    }
    else { // only left child
        node->_height = node->_left->_height + 1;
        return;
    }
}

template <class T>
void BinarySearchTree<T>::updatetree(TreeNode<T>* node)
{
    if(node == NULL) {
        return;
    }
    if(node->_left) {
        updatetree(node->_left);
    }
    if(node->_right) {
        updatetree(node->_right);
    }
    update(node);
}


template <class T>
TreeNode<T>* BinarySearchTree<T>::parent(T x)
{
    TreeNode<T>* temp = _root;
    TreeNode<T>* temp1 = NULL;
    while(temp->_item != x) {
        if(temp->_item > x) {
            temp1 = temp;
            temp = temp->_left;
        }
        else {
            temp1 = temp;
            temp = temp->_right;
        }
    }
    return temp1;
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::rotate(TreeNode<T>* node) {
    
    if (isBalanced(node) > 1) { //left heavy
        if (isBalanced(node->_left) < 0) { //left child is right heavy
            node->_left = _leftRotation(node->_left);
        }
        node = _rightRotation(node);
        return node;
    }
    
    else if (isBalanced(node) < -1) { //right heavy
        if (isBalanced(node->_right) > 0) { // right child is left heavy
            node->_right = _rightRotation(node->_right);
        }
        node = _leftRotation(node);
        return node;
    }
    
    else {// no rotation necessary
        return node;
    }
}

template <class T>
int BinarySearchTree<T>::isBalanced(TreeNode<T>* node) {
    if (node->_left == NULL && node->_right == NULL) { //no children
        return 0;
    }
    else if (node->_left != NULL && node->_right != NULL) { // 2 children
        return node->_left->_height - node->_right->_height;
    }
    else if (node->_left == NULL) { //only right child
        return -(node->_right->_height + 1);
    }
    else { // only left child
        return node->_left->_height + 1;
    }
}



