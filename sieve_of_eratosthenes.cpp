#include <stdio.h>
#include <math.h>

#define N 1000

using namespace std;

int isNotPrimeNumber[1001];

void sieveOfEratos() {
    int j;

    for (int i = 2; i <= sqrt(N); ++i) {
        if (isNotPrimeNumber[i] == 0) {
            j = 2;

            while (i * j <= N) {
                isNotPrimeNumber[i * j] = 1;
                ++j;
            }
        }
    }
}

int main() {
    sieveOfEratos();

    for (int i = 2; i <= N; ++i) {
        if (isNotPrimeNumber[i] == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}