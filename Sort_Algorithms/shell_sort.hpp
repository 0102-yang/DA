/*
 * @Author: Yang
 * @Copyright: Yang
 * @Date: 2021-02-09 13:09:49
 * @LastEditors: Yang
 * @LastEditTime: 2021-02-16 22:33:16
 * @FilePath: /DA/Sort_Algorithms/shell_sort.hpp
 */
// todo: if possible, try to use Hibbard or Sedgewick increment list!
/**
 * Shell sort.
 */
template <typename T>
void shell_sort(T arr[], int length) {
    // Validity check.
    if (length < 2 || arr == nullptr) {
        return;
    }
    T tmp;
    for (int increment = length / 2; increment > 0; increment /= 2) {
        for (int i = increment; i < length; i++) {
            tmp = arr[i];
            int j;
            for (j = i; j >= increment; j -= increment) {
                if (tmp < arr[j - increment]) {
                    arr[j] = arr[j - increment];
                } else {
                    break;
                }
            }
            arr[j] = tmp;
        }
    }
}