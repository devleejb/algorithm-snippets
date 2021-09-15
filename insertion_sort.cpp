#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; ++i) {
        for (int j = i; j > 0; --j) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
            } else {
                break;
            }
        }
    }
}

int main() {
    insertionSort(arr, 10);

    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}