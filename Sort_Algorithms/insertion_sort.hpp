/*
 * @Author: Yang
 * @Copyright: Yang
 * @Date: 2021-02-08 13:42:15
 * @LastEditors: Yang
 * @LastEditTime: 2021-02-18 22:59:19
 * @FilePath: /DA/Sort_Algorithms/insertion_sort.hpp
 */

/**
 * Insertion sort.
 */
class Insertion_Sort {
   public:
    template <typename T>
    void operator()(T arr[], int length);
};

template <typename T>
void Insertion_Sort::operator()(T arr[], int length) {
    // Validity check.
    if (length < 2 || arr == nullptr) {
        return;
    }

    // Select one element and insert it into previous ordered list.
    T tmp;
    for (int i = 1; i < length; i++) {
        int j;
        tmp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > tmp; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}