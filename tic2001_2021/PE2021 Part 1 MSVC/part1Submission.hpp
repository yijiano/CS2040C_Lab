#include <iostream>

using namespace std;

// if you use mac, just in case your code doesn't work, do this:
// sudo xcode-select --switch /Library/Developer/CommandLineTools/

template <class T>
T& List<T>::operator[](int idx) {
    return _head->_item;
}
template <class T>
void List<T>::insertAtPos(int idx, T item) {

}

template <class T>
void List<T>::removeAtPos(int idx){

    
}
