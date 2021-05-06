/*
 * @Author: Yang
 * @Copyright: Yang
 * @Date: 2021-02-11 17:49:02
 * @LastEditors: Yang
 * @LastEditTime: 2021-02-15 21:33:04
 * @FilePath: /DA/Algorithms/bubble_sort.hpp
 */
#include <functional>
template <typename T>
void bubble_sort(T arr[], int length) {
    // Validity check.
    if (length < 2 || arr == nullptr) {
        return;
    }

    bool flag;
    for (int i = 0; i < length - 1; i++) {
        flag = true;
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T e = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = e;
                flag = false;
            }
        }
        // If there is no swap in one loop, directly jump over the for-loop.
        if (flag) {
            break;
        }
    }
}