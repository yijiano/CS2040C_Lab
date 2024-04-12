#ifndef TREE_H
#define TREE_H

#include <algorithm>
#include <cassert>
#include <functional>
#include <string>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

using std::string;

template <typename T>
std::string my_to_string(const T& t) {
  return std::to_string(t);
}

template <>
std::string my_to_string(const std::string& t) {
  return "\"" + t + "\"";
}

template <typename T> struct Node {
  T element;
  int height;
  Node<T> *left;
  Node<T> *right;

  Node(T element)
      : element{element}, height{0}, left{nullptr}, right{nullptr} {}
  Node(T element, int height)
      : element{element}, height{height}, left{nullptr}, right{nullptr} {}
};

template <typename T> class Tree {
private:
  size_t m_size;
  Node<T> *m_root;

public:
  // Constructor
  Tree();

  // Rule of three:
  // If a class requires a user-defined destructor, a user-defined copy
  // constructor, or a user-defined copy assignment operator, it almost
  // certainly requires all three.

  // Destructor
  ~Tree();

  // Returns a pointer to the root
  Node<T> *root();

  // Deletes a node and its subtree from the tree
  void delete_node(Node<T> *node);

  // Checks whether the tree is empty
  bool empty() const;

  // Returns the number of elements
  size_t size() const;

  // Returns the height of the tree
  int height() const;

  // Inserts the specified element
  void insert(T element);

  // Checks whether the container contains the specified element
  bool contains(T element) const;

  // Returns the maximum element
  T max() const;

  // Returns the minimum element
  T min() const;

  // Returns the successor of the specified element
  T successor(T element);

  // Convert each element in the tree to string in pre-order.
  string pre_order();

  // Convert each element in the tree to string in order.
  string in_order();

  // Convert each element in the tree to string in post-order.
  string post_order();

  // Returns a string equivalent of the tree
  string to_string(bool with_height = true) const {
    return m_to_string(with_height, m_root, 0);
  }

private:
  string m_to_string(bool with_height, Node<T> *node, int ident) const {
    string res;
    if (node == nullptr) {
      return res;
    }
    if (node->right != nullptr) {
      res += m_to_string(with_height, node->right, ident + 2);
    }
    for (int i = 0; i < ident; i++) {
      res += " ";
    }
    res += my_to_string(node->element);
    if (with_height) {
      res += "(h=" + my_to_string(node->height) + ")";
    }
    res += "\n";
    if (node->left != nullptr) {
      res += m_to_string(with_height, node->left, ident + 2);
    }
    return res;
  }

  // Feel free to declare helper functions here, if necessary
};

// Constructor
template <typename T> Tree<T>::Tree() : m_root(nullptr), m_size(0) {}

// Deletes a node and its subtree from the tree
template <typename T> void Tree<T>::delete_node(Node<T> *node) {
  if (node != nullptr) {
    delete_node(node->left);
    delete_node(node->right);
    delete node;
  }
}

// Destructor
template <typename T> Tree<T>::~Tree() {
  delete_node(m_root);
}

// Returns a pointer to the root
template <typename T> Node<T> *Tree<T>::root() {
  return m_root;
}

// Checks whether the tree is empty
template <typename T> bool Tree<T>::empty() const {
  return m_root == nullptr;
}

// Returns the number of elements
template <typename T> size_t Tree<T>::size() const {
  return m_size;
}

// Returns the height of the tree
template <typename T> int Tree<T>::height() const {
  return m_root == nullptr ? -1 : m_root->height;
}

// Returns updated node height
template <typename T> int _insert_update_height(Node<T> *current) {
  int left_height = current->left ? current->left->height : -1;
  int right_height = current->right ? current->right->height : -1;
  return MAX(left_height, right_height) + 1;
}

// Right rotation for balancing
template <typename T> Node<T>* _insert_right_rotate(Node<T>* target) {
    Node<T>* pivot = target->left;
    Node<T>* subtree = pivot->right;

    pivot->right = target;
    target->left = subtree;

    target->height = _insert_update_height(target);
    pivot->height = _insert_update_height(pivot);

    return pivot;
}

// Left rotation for balancing
template <typename T> Node<T>* _insert_left_rotate(Node<T>* target) {
    Node<T>* pivot = target->right;
    Node<T>* subtree = pivot->left;

    pivot->left = target;
    target->right = subtree;

    target->height = _insert_update_height(target);
    pivot->height = _insert_update_height(pivot);

    return pivot;
}

// Returns balance factor of a node
template <typename T> int _insert_get_balance(Node<T>* node) {
  if (node == nullptr) return 0;
  int left_height = node->left ? _insert_update_height(node->left) : -1;
  int right_height = node->right ? _insert_update_height(node->right) : -1;
  return left_height - right_height;
}

// Helper function for insert
template <typename T> Node<T> *_insert(Node<T> *current, Node<T> *new_node) {
  if (current == nullptr) return new_node;

  if (new_node->element < current->element) {
    current->left = _insert(current->left, new_node);
  }
  else if (new_node->element > current->element) {
    current->right = _insert(current->right, new_node);
  }
  else return current;

  current->height = _insert_update_height(current);
  int balance = _insert_get_balance(current);
  
  // Left Left Case
  if (balance > 1 && new_node->element < current->left->element) {
    return _insert_right_rotate(current);
  }

  // Right Right Case
  if (balance < -1 && new_node->element > current->right->element) {
    return _insert_left_rotate(current);
  }

  // Left Right Case
  if (balance > 1 && new_node->element > current->left->element) {
    current->left = _insert_left_rotate(current->left);
    return _insert_right_rotate(current);
  }
  // Right Left Case
  if (balance < -1 && new_node->element < current->right->element) {
    current->right = _insert_right_rotate(current->right);
    return _insert_left_rotate(current);
  }
  return current;
}

// Inserts an element
template <typename T> void Tree<T>::insert(T element) {
  Node<T> *new_node = new Node<T>(element, 0);
  if (m_root == nullptr) m_root = new_node;
  else m_root = _insert(m_root, new_node);
  m_size++;
}

// Checks whether the container contains the specified element
template <typename T> bool Tree<T>::contains(T element) const {
  if (m_root == nullptr) return false;
  Node<T> *current = m_root;
  while (current != nullptr) {
    if (element < current->element) {
      current = current->left;
    } 
    else if (element > current->element) {
      current = current->right;
    } 
    else return true;
  }
  return false;
}

// Returns the maximum element
template <typename T> T Tree<T>::max() const {
  if (m_root == nullptr) {
    throw std::runtime_error("tree is empty");
  }
  Node<T> *current = m_root;
  while (current->right != nullptr) {
    current = current->right;
  }
  return current->element;
}

// Returns the minimum element
template <typename T> T Tree<T>::min() const {
  if (m_root == nullptr) {
    throw std::runtime_error("tree is empty");
  }
  Node<T> *current = m_root;
  while (current->left != nullptr) {
    current = current->left;
  }
  return current->element;
}

// Returns the successor of the specified element
template <typename T> T Tree<T>::successor(T element) {
  if (m_root == nullptr) {
    throw std::runtime_error("tree is empty");
  }
  Node<T> *current = m_root;
  Node<T> *curr_successor = nullptr;
  bool exit = false;

  while (!exit && current != nullptr) {
    if (element < current->element) {
      curr_successor = current;
      current = current->left;
    } 
    else if (element > current->element) {
      current = current->right;
    } 
    else {
      if (current->right != nullptr) {
        current = current->right;
        while (current->left != nullptr) current = current->left;
        return current->element;
      }
      break;
    }
  }
  if (curr_successor == nullptr) throw std::out_of_range("no successor");
  return curr_successor->element;
}

// Helper fucntion for pre_order
template <typename T> string _pre_order(Node<T> *node) {
  return my_to_string(node->element)
    + (node->left == nullptr ? "" : " " + _pre_order(node->left))
    + (node->right == nullptr ? "" : " " + _pre_order(node->right));
}

// Prints the tree in pre-order
template <typename T> string Tree<T>::pre_order() {
  if (m_root == nullptr) return "";
  return _pre_order(m_root);
}

// Helper fucntion for in_order
template <typename T> string _in_order(Node<T>* node) {
  return (node->left == nullptr ? "" : _in_order(node->left) + " ")
  + my_to_string(node->element)
  + (node->right == nullptr ? "" : " " + _in_order(node->right));
}

// Prints the tree in in-order
template <typename T> string Tree<T>::in_order() {
  if (m_root == nullptr) return "";
  return _in_order(m_root);
}

// Helper fucntion for post_order
template <typename T> string _post_order(Node<T>* node) {
  return (node->left == nullptr ? "" : _post_order(node->left) + " ")
  + (node->right == nullptr ? "" : _post_order(node->right) + " ")
  + my_to_string(node->element);
}

// Prints the tree in post-order
template <typename T> string Tree<T>::post_order() {
  if (m_root == nullptr) return "";
  return _post_order(m_root);
}

// template <typename T>
// string Tree<T>::level_order() const {
//     if (m_root == nullptr) return "";  // Return an empty string if the tree is empty

//     std::queue<Node<T>*> nodeQueue;
//     nodeQueue.push(m_root);  // Start with the root node
//     std::string result;

//     while (!nodeQueue.empty()) {
//         Node<T>* current = nodeQueue.front();
//         nodeQueue.pop();

//         // Process the current node
//         result += my_to_string(current->element) + " ";

//         // Enqueue child nodes of the current node
//         if (current->left != nullptr) nodeQueue.push(current->left);
//         if (current->right != nullptr) nodeQueue.push(current->right);
//     }

//     return result;
// }

#endif