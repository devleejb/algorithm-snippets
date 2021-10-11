#include <stdio.h>
#include <math.h>

using namespace std;

int isPrimeNumber(int n) {
    if (n == 1) return 0;

    for (int i = 2; i < sqrt(n); ++i) {
        if (n % i == 0) {
            return 0;
        }    
    }

    return 1;
}

int main() {
    printf("%d", isPrimeNumber(101));

    return 0;
}