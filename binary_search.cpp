#include <stdio.h>

using namespace std;

int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// return index of target number
int binarySearch(int* arr, int target, int start, int end) {
    int mid = (start + end) / 2;

    if (start > end) {
        return -1;
    }

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return binarySearch(arr, target, start, mid -1);
    } else {
        return binarySearch(arr, target, mid + 1, end);
    }
}

int main() {
    int targetIdx;

    targetIdx = binarySearch(arr, 4, 0, 9);

    printf("%d", targetIdx);

    return 0;
}