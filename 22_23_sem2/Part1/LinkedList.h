

#include <iostream>
using namespace std;

#define SPLITSTR "Splitting: "
#define INTOSTR "Into :"
#define MERGESTR "Merging: "


class ListNode {

private:
    int _item;
    ListNode* _next;

public:
    ListNode( int );        // Constructs the list node with parameter
    void printItem();       // Prints the item

    friend class List;
};

class List {

private:
    ListNode* _head;
    int _size;

public:
    List();                             // Constructs an empty list
    ~List();                            // Destructs a list

    void insertHead( int );             // Inserts the new value into the linked list
    int getHeadItem();                  // Retrieves the value in the head node
    int removeHead();                   // Removes the head node and returns the value removed

    void bubbleSort();            // TODO: Implement bubble sort
    void mergeSort();                   // Calls the recursive merge sort function

    void split( List* );                // TODO: Splits the linked lists into two halves
    void merge( List* );                // TODO: Merge two linked lists in ascending order

    void print();                 // Prints all items of the linked lists.
};








/*
 * LISTNODE CONSTRUCTUORS AND FUNCTIONS
 */
ListNode::ListNode(int item) {
    _item = item;
    _next = NULL;
}

void ListNode::printItem() {
    cout << _item;
}


/*
 * LIST CONSTRUCTORS AND FUNCTIONS
 */
List::List() {
    _head = NULL;
    _size = 0;
}

List::~List() {
    while (_head) {
        removeHead();
    }
}

void List::insertHead(int item) {
    ListNode* newNode = new ListNode(item);
    newNode->_next = _head;
    _head = newNode;
    _size++;
}

int List::getHeadItem() {
    return _head->_item;
}

int List::removeHead() {
    int item = -32768;  
    ListNode* temp;

    if (_head) {
        temp = _head;
        item = getHeadItem();
        _head = _head->_next;
        delete temp;
        _size--;
    }

    return item;
}

void List::bubbleSort() {

    // TODO: Implement bubble sort on this implementation of single linked list.
    //       Print the linked list after every pass in the outer iteration
    //       using print(false) function in List class if parameter is true.
    //       The list should be sorted in ascending order.

    // ENTER YOUR ANSWER BELOW.


    bool swapped;
    do {
        swapped = false;
        ListNode* current = _head;
        while (current && current->_next) {
            if (current->_item > current->_next->_item) {
                std::swap(current->_item, current->_next->_item);
                swapped = true;
            }
            current = current->_next;
        }
    } while (swapped);


    // ENTER YOUR ANSWER ABOVE.
}

void List::mergeSort() {

    // modify this function
    // 
    // each time you split a list
    cout << SPLITSTR;
    // original unsplitted list print
    print();
    cout << INTOSTR << endl;
    // original splitted list print (but it's halved)
    // the other splitted list print


    // after you sorted the two lists
    cout << MERGESTR << endl;
    // original splitted list print (but it's halved)
    // the other splitted list print
    
    // after you merged the above two sorted lists
    cout << INTOSTR;
    // print the merged sorted single list
    print();

}


void List::split(List* otherList) {
    // TODO: Implement splitting of the current list.
    //       The first half of the list will be pointed by itself.
    //       The second half of the list will be pointed by otherList.
    //       It is guaranteed that the original list will have more than one node.
    //
    //       No need to print within split()
    
    // ENTER YOUR ANSWER BELOW.
    ListNode* current = _head;
    for (int i = 0; i < _size / 2 - 1; i++) {
        current = current->_next;
    }
    otherList->_head = current->_next;
    current->_next = nullptr;

   // ENTER YOUR ANSWER ABOVE.
}

void List::merge(List* otherList) {
    // TODO: Implement merging of current list and otherList.
    //       The otherList should be empty after merging.
    //       It is guaranteed that both lists are non-empty.
    //
    //       No need to print within merge()
    // ENTER YOUR ANSWER BELOW.

    ListNode* current = _head;
    while (current->_next != nullptr) {
        current = current->_next;
    }
    current->_next = otherList->_head;
    otherList->_head = nullptr;
    otherList->~List();
    bubbleSort();

    // ENTER YOUR ANSWER ABOVE.
}

void List::print() {

    ListNode* curr = _head;

    while (curr) {
        cout << curr->_item;
        cout << " ";
        curr = curr->_next;
    }

    cout << endl;
}


#include <iostream>

class Node {
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class List {
public:
    Node* head;

    List() : head(nullptr) {}

    ~List() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Helper function to add elements to the end of the list
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to merge another list into this one
    void merge(List* other) {
        if (other == nullptr) return;

        Node* current = head;
        if (current == nullptr) {
            head = other->head;
        } else {
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = other->head;
        }
        other->head = nullptr;  // Detach nodes from 'other' list

        head = mergeSort(head);  // Sort the merged list
    }

private:
    Node* mergeSort(Node* node) {
        if (node == nullptr || node->next == nullptr) {
            return node;
        }

        Node* middle = getMiddle(node);
        Node* nextOfMiddle = middle->next;
        middle->next = nullptr;

        Node* left = mergeSort(node);
        Node* right = mergeSort(nextOfMiddle);

        return sortedMerge(left, right);
    }

    Node* sortedMerge(Node* a, Node* b) {
        Node* result = nullptr;
        if (a == nullptr) return b;
        else if (b == nullptr) return a;

        if (a->value <= b->value) {
            result = a;
            result->next = sortedMerge(a->next, b);
        } else {
            result = b;
            result->next = sortedMerge(a, b->next);
        }
        return result;
    }

    Node* getMiddle(Node* head) {
        if (head == nullptr) return head;
        Node* slow = head;
        Node* fast = head->next;
        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }
};

// Usage example:
int main() {
    List list1;
    list1.append(3);
    list1.append(1);
    list1.append(4);

    List list2;
    list2.append(2);
    list2.append(5);

    list1.merge(&list2);

    for (Node* node = list1.head; node != nullptr; node = node->next) {
        std::cout << node->value << " ";
    }
    std::cout << std::endl;

    return 0;
}


//class List {
//public:
//    Node* head;
//
//    List() : head(nullptr) {}
//
//    ~List() {
//        Node* current = head;
//        while (current != nullptr) {
//            Node* next = current->next;
//            delete current;
//            current = next;
//        }
//    }
//
//    // Helper function to add elements to the end of the list
//    void append(int value) {
//        Node* newNode = new Node(value);
//        if (head == nullptr) {
//            head = newNode;
//        }
//        else {
//            Node* current = head;
//            while (current->next != nullptr) {
//                current = current->next;
//            }
//            current->next = newNode;
//        }
//    }
//
//    // Function to merge another list into this one
//    void merge(List* other) {
//        if (other == nullptr) return;
//
//        Node* current = head;
//        if (current == nullptr) {
//            head = other->head;
//        }
//        else {
//            while (current->next != nullptr) {
//                current = current->next;
//            }
//            current->next = other->head;
//        }
//        other->head = nullptr;  // Detach nodes from 'other' list
//
//        head = mergeSort(head);  // Sort the merged list
//    }
//
//private:
//    Node* mergeSort(Node* node) {
//        if (node == nullptr || node->next == nullptr) {
//            return node;
//        }
//
//        Node* middle = getMiddle(node);
//        Node* nextOfMiddle = middle->next;
//        middle->next = nullptr;
//
//        Node* left = mergeSort(node);
//        Node* right = mergeSort(nextOfMiddle);
//
//        return sortedMerge(left, right);
//    }
//
//    Node* sortedMerge(Node* a, Node* b) {
//        Node* result = nullptr;
//        if (a == nullptr) return b;
//        else if (b == nullptr) return a;
//
//        if (a->value <= b->value) {
//            result = a;
//            result->next = sortedMerge(a->next, b);
//        }
//        else {
//            result = b;
//            result->next = sortedMerge(a, b->next);
//        }
//        return result;
//    }
//
//    Node* getMiddle(Node* head) {
//        if (head == nullptr) return head;
//        Node* slow = head;
//        Node* fast = head->next;
//        while (fast != nullptr) {
//            fast = fast->next;
//            if (fast != nullptr) {
//                slow = slow->next;
//                fast = fast->next;
//            }
//        }
//        return slow;
//    }
//};