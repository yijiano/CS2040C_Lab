
#ifndef part2_header
#define part2_header

class Sorter {
 public:
  /**
   * @brief Perform insertion sort on the given array.
   *
   * @param arr Pointer to first element of the array.
   * @param start Starting index of the array.
   * @param end Ending index of the array.
   */
  void insertionSort(int *arr, int start, int end);

  /**
   * @brief Partition the array using the first element as the pivot.
   *
   * @param arr Pointer to first element of the array.
   * @param start Starting index of the array.
   * @param end Ending index of the array.
   * @return int Index of the pivot element after partitioning.
   */
  int partition_first(int *arr, int start, int end);

  /**
   * @brief Perform quicksort on the given array.
   *
   * @param arr Pointer to first element of the array.
   * @param start Starting index of the array.
   * @param end Ending index of the array.
   * @param useISwhenLength When length of array to sort becomes less than or
   * equal to this value, use insertion sort.
   */
  void quickSort(int *arr, int start, int end, int useISwhenLength = 0);

 protected:
  /**
   * @brief Call this method on each step of insertion sort.
   *
   * @param arr Pointer to first element of the array.
   * @param start Starting index of the array.
   * @param end Ending index of the array.
   * @param slotIndex Index to highlight (see instructions).
   */
  virtual void insertionSort_Step(int *arr, int start, int end, int slotIndex) {
  }

  /**
   * @brief Call this method on each partition.
   *
   * @param arr Pointer to first element of the array.
   * @param start Starting index of the array.
   * @param end Ending index of the array.
   * @param pivotIndex Index of the pivot (see instructions).
   */
  virtual void parition_first_Step(int *arr, int start, int end,
                                   int pivotIndex) {}
};

#endif /* part2_header */
