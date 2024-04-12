

void HashTable::insert(int n) {

    // default output format for error message
    //cout << n << " already exists in the hash table."<<endl;
    int probe = 0;
    int index = h(n);  // Initial hash index

    while (probe < _size) {  // We will never insert more items than the table size
        int current_index = (index + probe * probe) % _size;
        if (_ht[current_index] == 0 || _ht[current_index] == -1) {  // Check for empty or deleted slot
            _ht[current_index] = n;
            _nItem++;
            return;
        } else if (_ht[current_index] == n) {
            cout << n << " already exists in the hash table." << endl;
            return;
        }
        probe++;
    }
}

//n does not necasarrily exist in the hash table
void HashTable::remove(int n) {
    // default output format for error message
    //cout << "Fail to remove " << n << endl;
    int probe = 0;
    int index = h(n);

    while (probe < _size) {
        int current_index = (index + probe * probe) % _size;
        if (_ht[current_index] == n) {
            _ht[current_index] = -1;  // Mark as deleted
            return;
        } else if (_ht[current_index] == 0) {  // Empty slot, stop search
            break;
        }
        probe++;
    }
    cout << "Fail to remove " << n << endl;
}

bool HashTable::exist(int n) {
    bool HashTable::exist(int n) {
    int probe = 0;
    int index = h(n);

    while (probe < _size) {
        int current_index = (index + probe * probe) % _size;
        if (_ht[current_index] == n) {
            return true;
        } else if (_ht[current_index] == 0) {  // Empty slot, stop search
            return false;
        }
        probe++;
    }
    return false;
}
}


void HashTable::resize(int newSize) {
    // Allocate new hash table with the new size, initialized to 0 (empty)
    int* newTable = new int[newSize]();
    for (int i = 0; i < newSize; i++) {
        newTable[i] = 0;
    }

    // Rehash elements from the old table to the new table
    for (int i = 0; i < _size; i++) {
        if (_ht[i] > 0) {  // Rehash only valid items, skipping deleted ones (marked as -1) and empty ones (marked as 0)
            int elem = _ht[i];
            int probe = 0;
            int index = h(elem);  // Use the same hash function

            // Find the new position using quadratic probing
            while (probe < newSize) {
                int newIndex = (index + probe * probe) % newSize;
                if (newTable[newIndex] == 0) {  // Check for empty spot
                    newTable[newIndex] = elem;
                    break;
                }
                probe++;
            }
        }
    }

    // Delete the old table and update the pointer
    delete[] _ht;
    _ht = newTable;
    _size = newSize;  // Update the size of the hash table
}

int n3Sum(int* arr, int size, int total)
{
    int n3Sum(int* arr, int size, int total) {
    sort(arr, arr + size);
    int count = 0;

    for (int i = 0; i < size - 2; ++i) {
        int left = i + 1, right = size - 1;
        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == total) {
                count++;
                left++;
                right--;
            } else if (sum < total) {
                left++;
            } else {
                right--;
            }
        }
    }
    return count;
}
}
