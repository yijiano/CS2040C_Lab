#include <iostream>
using namespace std;

/**
 * @brief Node within a binary search tree.
 * Contains left and right children, as well as the height of the node.
 * Only meant to be used from BinarySearchTree.
 *
 * @tparam T type to be stored.
 */
template <class T>
class TreeNode {
 public:
  // Members would normally be private, but are made public to
  // simplify the current exercise.

  // Item stored within the node.
  T _item;

  // Left and right children. Obey the BST invariant.
  TreeNode<T> *_left;
  TreeNode<T> *_right;

  // Height of the current node.
  int _height;

  // Construct leaf node (no children) with given item.
  TreeNode(T x) {
    _left = _right = nullptr;
    _item = x;
    _height = 0;
  };
};

/**
 * @brief Binary Search Tree generic implementation.
 * Should be the same as in your assignments.
 *
 * @tparam T typedef for storage at each node.
 */
template <class T>
class BinarySearchTree {
 protected:
  // Number of nodes in the tree.
  int _size;

  // Root of the tree.
  TreeNode<T> *_root;

  // Helper method to print the current tree. Useful for debugging.
  void _printTree(int indent, TreeNode<T> *, bool withHeight);

  // Internal helpers.
  TreeNode<T> *_insert(TreeNode<T> *current, T x);
  void _destroySubTree(TreeNode<T> *);

 public:
  // Default constructor initializes an empty tree.
  BinarySearchTree() : _root(nullptr), _size(0) {}

  // Recursively delete the tree.
  ~BinarySearchTree();

  // Number of nodes in the tree.
  int size() { return _size; };

  // Insert an item into the tree (if it does not already exist),
  // respecting the BST invariant.
  void insert(T);

  // Print the tree structure to stdout.
  void printTree(bool withHeight = 1);

  // Traverse the tree in level order and populate the given array.
  // Assumes that the array is large enough to store all elements.
  void levelOrderTraversal(T *arr);
};

template <class T>
void BinarySearchTree<T>::insert(T x) {
  _root = _root ? _insert(_root, x) : new TreeNode<T>(x);
  if (_size == 0) _size++;
}

template <class T>
void BinarySearchTree<T>::_printTree(int indent, TreeNode<T> *node,
                                     bool withHeight) {
  if (!node) return;

  if (node->_right) _printTree(indent + 2, node->_right, withHeight);
  for (int i = 0; i < indent; i++) cout << "  ";
  cout << node->_item;
  if (withHeight) cout << "(h=" << node->_height << ")";
  cout << endl;
  if (node->_left) _printTree(indent + 2, node->_left, withHeight);
};

template <class T>
void BinarySearchTree<T>::printTree(bool withHeight) {
  _printTree(0, _root, withHeight);
}

template <class T>
void BinarySearchTree<T>::_destroySubTree(TreeNode<T> *node) {
  if (node->_left) _destroySubTree(node->_left);
  if (node->_right) _destroySubTree(node->_right);
  delete node;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
  if (_root) _destroySubTree(_root);
}

template <class T>
TreeNode<T> *BinarySearchTree<T>::_insert(TreeNode<T> *current, T x) {
  // Base case
  if (current == nullptr) {
    _size++;
    return new TreeNode<T>(x);
    ;
  }

  // ignore duplicates
  if (x == current->_item) return current;

  if (x < current->_item) {
    current->_left = _insert(current->_left, x);
  } else {
    current->_right = _insert(current->_right, x);
  }
  // update height ?

  return current;
}

