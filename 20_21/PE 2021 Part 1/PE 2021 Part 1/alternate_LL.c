#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() : head(nullptr) {}

    // Function to add element to the circular linked list
    void add(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            head->next = head;  // Points to itself, making it circular
        } else {
            Node* temp = head;
            while (temp->next != head) {  // Find the last node
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;  // Make it circular
        }
    }

    // Function to shift the head to the next element
    void shiftHead() {
        if (head) {
            head = head->next;  // Move the head pointer to the next node
        }
    }

    // Optional: Function to display the list
    void display(int count) {  // Count controls the number of elements to display to avoid infinite loop
        if (!head) return;
        Node* temp = head;
        while (count-- > 0) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "..." << endl;  // Indicates that it is circular
    }
};

int main() {
    CircularLinkedList clist;
    clist.add(1);
    clist.add(2);
    clist.add(3);
    clist.display(10);

    clist.shiftHead();
    clist.display(10);

    return 0;
}
