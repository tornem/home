#include <stdio.h>
#include <stdlib.h>

#define N 10000

void Swap(int* first, int* second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void InsertSorting(int sortering_arr[])
{
    for (int i = 0, j = 0; i < N - 1; ++i) {
        j = i + 1;
        while (sortering_arr[j] < sortering_arr[j - 1]
                && j > 0) {
            Swap(sortering_arr + j, sortering_arr + (j - 1));
            --j;
        }
    }
}

int main()
{
    int not_sorted_arr[N];

    for (int i = 0; i < N; ++i){
        not_sorted_arr[i] = rand() % 100;
    }

    for (int i = 0; i < N; ++i) {
        printf("%d ", not_sorted_arr[i]);
    }
    
    puts("\n");

    InsertSorting(not_sorted_arr);


    for (int i = 0; i < N; ++i) {
        printf("%d ", not_sorted_arr[i]);
    }
    puts("\n");

}