/*
 * @Author: Yang
 * @Copyright: Yang
 * @Date: 2021-02-18 22:41:21
 * @LastEditors: Yang
 * @LastEditTime: 2021-02-18 23:02:50
 * @FilePath: /DA/Sort_Algorithms/quick_sort.hpp
 */
#include "insertion_sort.hpp"

class QuickSort {
public:
    template<typename T>
    void operator()(T arr[], int length);

private:
    template<typename T>
    void q_sort(T arr[], int left, int right);

    template<typename T>
    T median3(T arr[], int left, int right);

private:
    const int cutoff = 3;
};

template<typename T>
void QuickSort::operator()(T arr[], int length) {
    q_sort(arr, 0, length - 1);
}

template<typename T>
void QuickSort::q_sort(T arr[], int left, int right) {
    if (left + cutoff <= right) {
        T pivot = median3(arr, left, right);
        int i = left, j = right - 1;

        while (true) {
            while (arr[++i] < pivot) {
            }
            while (arr[--j] > pivot) {
            }
            if (i < j) {
                std::swap(arr[i], arr[j]);
            } else {
                break;
            }
        }

        std::swap(arr[i], arr[right - 1]);

        q_sort(arr, left, i - 1);
        q_sort(arr, i + 1, right);
    } else {
        Insertion_Sort()(arr + left, right - left + 1);
    }
}

template<typename T>
T QuickSort::median3(T arr[], int left, int right) {
    int center = (left + right) / 2;

    if (arr[left] > arr[center]) {
        std::swap(arr[left], arr[center]);
    }
    if (arr[left] > arr[right]) {
        std::swap(arr[left], arr[right]);
    }
    if (arr[center] > arr[right]) {
        std::swap(arr[center], arr[right]);
    }

    std::swap(arr[center], arr[right - 1]);
    return arr[right - 1];
}