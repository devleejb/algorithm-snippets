#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
int cnt[10];

// K : arr 내 원소의 최댓값
void countingSort(int* arr, int K, int size) {
    int idx = 0;

    for (int i = 0; i < size; ++i) {
        ++cnt[arr[i]];
    }

    for (int i = 0; i <= K; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            arr[idx++] = i;
        }
    }
}


int main() {
    countingSort(arr, 9, 10);

    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}