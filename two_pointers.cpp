#include <stdio.h>

using namespace std;

int intervalSum, cnt, targetSum = 5;
int arr[5] = {1, 2, 3, 4, 5};


void countSeq(int N) {
    int end = 0;

    for (int start = 0; start < N; ++start) {
        while (intervalSum < targetSum && end < N) {
            intervalSum += arr[end];
            ++end;
        }

        if (intervalSum == targetSum) ++cnt;

        intervalSum -= arr[start];
    }
}

int main() {
    countSeq(5);

    printf("%d", cnt);

    return 0;
}