/*
 * @Author: Yang
 * @Copyright: Yang
 * @Date: 2021-02-10 02:02:29
 * @LastEditors: Yang
 * @LastEditTime: 2021-02-15 21:29:14
 * @FilePath: /DA/Algorithms/selection_sort.hpp
 */

template <typename T>
void selection_sort(T arr[], int length) {
    // Validity check.
    if (length < 2 || arr == nullptr) {
        return;
    }
    int min_index;
    for (int i = 0; i < length - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (i != min_index) {
            T e = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = e;
        }
    }
}