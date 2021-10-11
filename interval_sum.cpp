#include <stdio.h>

using namespace std;

int arr[5] = {1, 2, 3, 4, 5};
int prefixSum[6];
int sumVal;

void calPrefixSum(int n) {
    for (int i = 0; i <= n; ++i) {
        prefixSum[i + 1] = sumVal += arr[i];
    }
}

// Return Interval Sum [start, end]
int intervalSum(int start, int end) {
    return prefixSum[end] - prefixSum[start - 1];
}

int main() {
    calPrefixSum(5);

    printf("%d", intervalSum(1, 4));

    return 0;
}