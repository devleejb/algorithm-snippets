#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

void selectionSort(int* arr, int size) {
    int minIdx;

    for (int i = 0; i < size - 1; ++i) {
        minIdx = i;

        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        swap(arr[minIdx], arr[i]);
    }
}

int main() {
    selectionSort(arr, 10);

    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}