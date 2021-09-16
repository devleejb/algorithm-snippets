#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

int partition(int* arr, int start, int end) {
    int pivot = arr[end];
    int wall = start - 1;

    for (int i = start; i < end; ++i) {
        if (arr[i] <= pivot) {
            ++wall;
            swap(arr[i], arr[wall]);
        }
    }

    swap(arr[wall + 1], arr[end]);

    return wall + 1;
}

void quickSort(int* arr, int start, int end) {
    if (start < end) {
        int pivotIdx = partition(arr, start, end);

        quickSort(arr, start, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, end);
    }
}

int main() {
    quickSort(arr, 0, 9);

    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}