/*
 * @Author: Yang
 * @Copyright: Yang
 * @Date: 2021-02-17 00:13:54
 * @LastEditors: Yang
 * @LastEditTime: 2021-02-18 19:21:20
 * @FilePath: /DA/Sort_Algorithms/merge_sort.hpp
 */

template <typename T>
void merge(T arr[], T tmp_array[], int left_pos, int right_pos, int right_end) {
    int left_end = right_pos - 1;
    int tmp_pos = left_pos;
    int num_elements = right_end - left_pos + 1;

    while (left_pos <= left_end && right_pos <= right_end) {
        if (arr[left_pos] <= arr[right_pos]) {
            tmp_array[tmp_pos++] = arr[left_pos++];
        } else {
            tmp_array[tmp_pos++] = arr[right_pos++];
        }
    }

    while (left_pos <= left_end) {
        tmp_array[tmp_pos++] = arr[left_pos++];
    }
    while (right_pos <= right_end) {
        tmp_array[tmp_pos++] = arr[right_pos++];
    }

    for (int i = 0; i < num_elements; i++, right_end--) {
        arr[right_end] = tmp_array[right_end];
    }
}

template <typename T>
void m_sort(T arr[], T tmp_array[], int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;
        m_sort(arr, tmp_array, left, center);
        m_sort(arr, tmp_array, center + 1, right);
        merge(arr, tmp_array, left, center + 1, right);
    }
}

template <typename T>
void merge_sort(T arr[], int length) {
    T* tmp_array = new T[length];

    m_sort(arr, tmp_array, 0, length - 1);

    delete[] tmp_array;
}