#include "linked_list.h"
#include <stdexcept>

// Returns the value at head
int List::head() {
  if (m_head == nullptr) {
    throw std::out_of_range("Cannot read head from empty list.");
  }
  return m_head->element;
}

// Checks whether the container is empty
bool List::empty() const {
  return m_head == nullptr;
}

// Returns the number of elements
size_t List::size() const {
  return m_size;
}

void List::push_head(int element) {
  Node* new_head = new Node{element, m_head};
  m_head = new_head;
  m_size += 1;
}

// Removes the head element
int List::pop_head() {
  if (m_head == nullptr) {
    throw std::out_of_range("Cannot pop from an empty list.");
  }
  Node* old_head = m_head;
  int old_element = old_head->element;
  m_head = m_head->next;
  delete old_head;
  m_size -= 1;
  return old_element;
}

// Checks whether the container contains the specified element
bool List::contains(int element) const {
  Node* curr_node = m_head;
  while (curr_node != nullptr) {
    if (curr_node->element == element) return true;
    curr_node = curr_node->next;
  }
  return false;
}

// Returns a std::string equivalent of the container
std::string List::to_string() const {
  if (m_size == 0) return "{}";
  if (m_size == 1) return "{" + std::to_string(m_head->element) + "}";
  std::string output = "{";
  Node* temp = m_head;
  do {
    output += std::to_string(temp->element) + ", ";
    temp = temp->next;
  } while (temp->next != nullptr);
  output += std::to_string(temp->element) + "}";
  return output;
}
