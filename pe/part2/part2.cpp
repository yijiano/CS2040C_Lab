
void Sorter::insertionSort(int *arr, int start, int end) {
  for (int i = start + 1; i < end; i ++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= start && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
      arr[j + 1] = key;
    }
    insertionSort_Step(arr, start, end, j + 1);
  }
}

int Sorter::partition_first(int *arr, int start, int end) {
    if (start == end) return -1; // error: array is empty
    if (start == end - 1) return 0; // single element array
    int pivot = arr[start];
    int low = start + 1;
    int high = end - 1;
    while (low < high) {
      while ((arr[low] < pivot) && (low < high)) {
        low++;
      }
      while ((arr[high] > pivot) && (low < high)) {
        high--;
      }
      if (low < high) {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
      }
    }
    int temp = arr[start];
    arr[start] = arr[low - 1];
    arr[low - 1] = temp;
    parition_first_Step(arr, start, end, low - 1);
    return low - 1;
}

void Sorter::quickSort(int *arr, int start, int end, int useISwhenLength) {
  if (start == end) return;

  if (end - start <= useISwhenLength) {
    insertionSort(arr, start, end);
  }

  int pi = partition_first(arr, start, end);
  quickSort(arr, start, pi - 1, useISwhenLength);
  quickSort(arr, pi + 1, end, useISwhenLength);
}
