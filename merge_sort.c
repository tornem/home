#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void Merge(int* array, int left_index, int right_index, int arr_size)  // left_index < right_index < arr_size
{
    int left_size = right_index - left_index + 1;
    int right_size = arr_size - right_index;

    int* left_arr = malloc(left_size * sizeof(left_size));  
    int* right_arr = malloc(right_size * sizeof(right_size)); 

    memcpy(left_arr, array + left_index - 1, left_size * sizeof(*array));
    memcpy(right_arr, array + right_index, right_size * sizeof(*array));
    // int left_arr[left_size + 1];
    // int right_arr[right_size + 1];

    // for (int i = 0; i < left_size; ++i) {
    //     left_arr[i] = array[left_index+i-1];
    // }

    // for (int i = 0; i < right_size; ++i) {
    //     right_arr[i] = array[right_index + i];
    // }

    // left_arr[left_size] = INT_MAX;  // маркер, который указывает, на конец данного массива.
    // right_arr[right_size] = INT_MAX;

    for (int k = left_index - 1, i = 0, j = 0; k < arr_size; ++k) {
        if (i == left_size) {
            memcpy(array + k, right_arr + j, (right_size - j) * sizeof(*right_arr));
            break;
        }
        if (j == right_size) {
            memcpy(array + k, left_arr + i, (left_size - i) * sizeof(*left_arr));
            break;
        }
        if (left_arr[i] <= right_arr[j]) {
            array[k] = left_arr[i];
            ++i;
        } else {
            array[k] = right_arr[j];
            ++j;
        }
    }

    free(left_arr);
    free(right_arr);
}

void MergeSort(int* array, const int left_start, const int size )
{
    int right_start = (size + left_start) / 2;
    if (left_start >= size) {  // если кол-во элементов меньше 2х ( 1 элемент или пустой список = отсортированный список)
        return;
    }
    MergeSort(array, left_start, right_start);  // сортируем левую часть массива
    MergeSort(array, right_start + 1, size);  // теперь правую
    Merge(array, left_start, right_start, size);
}

int main()
{
    int test_arr[] = {1, 3, 0 ,2 ,4};
    size_t size = sizeof(test_arr)/sizeof(*test_arr);
    //printf("%lu\n", sizeof(test_arr)/sizeof(*test_arr));

    MergeSort(test_arr, 1, size);

    for (int i = 0; i < size; ++i) {
        printf("%d\n", test_arr[i]);
    }

    return 0;
}
