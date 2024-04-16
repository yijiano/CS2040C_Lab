
template <class T>
void BinarySearchTree<T>::levelOrderTraversal(T* arr) {
  if (_root == nullptr) return;  // Return an empty string if the tree is empty

  TreeNode<T>** queue = new TreeNode<T>* [_size]; //simulated queue
  int front = 0; // front of remaining queue
  int back = 0; // back of remainng queue
  int arr_index = 0; // which index to insert to arr
  queue[front] = _root;

  while (front <= back) {
    TreeNode<T>* current = queue[front];
    front++;

    // Process the current node into arr
    arr[arr_index] = current->_item;
    arr_index++;

    // "Enqueue" child nodes of the current node
    if (current->_left != nullptr) {
      back++;
      queue[back] = current->_left;
    } 
    if (current->_right != nullptr) {
      back++;
      queue[back] = current->_right;
    }
  }
  delete[] queue;
}