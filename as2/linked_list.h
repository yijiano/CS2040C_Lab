#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <initializer_list>
#include <string>

template<typename T>
std::string format_Element(const T& element) {
    std::ostringstream oss;
    oss << element;
    return oss.str();
}

template<>
std::string format_Element<std::string>(const std::string& element) {
    return "\"" + element + "\"";
}

template <typename T> struct Node {
  T element;
  Node<T> *next;

  Node(T element) : element{element}, next{nullptr} {}
  Node(T element, Node<T> *next) : element{element}, next{next} {}
};

template <typename T> class List {
private:
  size_t m_size;
  Node<T> *m_head;

  // Feel free to add helper functions here, if necessary

public:
  // Constructs an empty container
  List() : m_size{0}, m_head{nullptr} {}

  // Constructs the container with the contents of the initializer list
  List(std::initializer_list<T> init_list) : m_size{0}, m_head{nullptr} {
    auto it = init_list.end();
    while (--it != init_list.begin()) {
      push_head(*it);
    }
    push_head(*it);
  }

  // Rule of three:
  // If a class requires a user-defined destructor, a user-defined copy
  // constructor, or a user-defined copy assignment operator, it almost
  // certainly requires all three.

  // Destructor
  ~List() {
    Node<T> *current = m_head; // Start from the head of the list
    while (current) {
        Node<T> *next = current->next; // Save the next node
        delete current; // Deallocate the current node
        current = next; // Move to the next node
    }
    m_head = nullptr;
  }

  // Copy constructor
  List(const List<T> &other) {
    if (other.empty()) {
      throw std::out_of_range("Target List is empty");
    }
    other.reverse();
    while (!other.empty()) {
      push_head(other.head());
      other.pop_head();
    }
    other.~List();
  }

  // Copy assignment
  List<T> &operator=(const List<T> &other) {
    // TODO: (Optional) Implement this method
  }

  // Returns the contents of the head node
  const T& head() {
    if (m_size <= 0) {
      throw std::out_of_range("List is empty");
    }
    return m_head->element;
  }

  // Checks whether the container is empty
  bool empty() const { return m_size == 0; }

  // Returns the number of elements
  size_t size() const { return m_size; }

  // Inserts an element to the head
  void push_head(const T& element) {
    Node<T> *node = new Node<T>{element, m_head};
    m_head = node;
    m_size++;
  }

  // Removes the head element
  void pop_head() {
    if (m_size <= 0) {
      throw std::out_of_range("List is empty");
    }

    Node<T> *node = m_head;
    m_head = m_head->next;
    delete node;
    m_size--;
  }

  // [HELPER FUNCTION] Appends node to end of container
  void append_tail(const T& element) {
    Node<T> *new_tail = new Node<T>{element};
    Node<T> *current = m_head;
    while (current->next) current = current->next;
    current->next = new_tail;
    m_size++;
  }

  //[HELPER FUNCTION] Pops last element
  void pop_tail() {
    if (m_size <= 0) {
      throw std::out_of_range("List is empty");
    }
    Node<T> *current = m_head;
    while ((current->next)->next) current = current->next;
    Node<T> *tail = current->next;
    current->next = nullptr;
    delete tail;
    m_size--;
  }

  //[HELPER FUNCTION] Returns tail
  const T& tail() {
    if (m_size <= 0) {
      throw std::out_of_range("List is empty");
    }
    Node<T> *current = m_head;
    while (current->next) current = current->next;
    return current->element;
  }

  //[HELPER FUNCTION] Returns head node
  Node<T> *head_node() {
    if (m_size <= 0) {
      throw std::out_of_range("List is empty");
    }
    return m_head;
  }

  // Checks whether the container contains the specified element
  bool contains(const T& element) const {
    if (empty()) {
      return false;
    }
    Node<T> *current = m_head;
    while (current) {
      if (current->element == element) return true;
      current = current->next;
    }
    return false;
  }

  // Extracts the maximum element from the container
  T extract_max() {
    if (empty()) {
      throw std::out_of_range("List is empty");
    }
    Node<T> *current = m_head;
    T maximum = m_head->element;
    while (current) {
      if (current->element > maximum) maximum = current->element;
      current = current->next;
    }
    return maximum;
    // throw std::logic_error("extract_max not yet implemented");
  }

  void reverse() {
    if (m_size <= 1) {
      return;
    }
    Node<T> *prev = nullptr;
    Node<T> *current = m_head;
    Node<T> *next = nullptr;
    while (current) {
      next = current->next;    
      current->next = prev;    
      prev = current;
      current = next;
    }
    m_head = prev;
  }

  // Returns a std::string equivalent of the container
  std::string to_string() const {
    std::ostringstream oss;
    oss << "{";
    Node<T> *current = m_head;
    while (current != nullptr) {
      oss << format_Element(current->element); // Formats element based on its type
      if (current->next != nullptr) oss << ", ";
      current = current->next;
    }
    oss << "}";
    return oss.str();
  }
};

#endif
