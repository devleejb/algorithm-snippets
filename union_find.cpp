#include <stdio.h>

using namespace std;

int parent[1001];

int findParent(int x) {
    if (parent[x] != x) parent[x] = findParent(parent[x]);

    return parent[x];
}

void unionSet(int a, int b) {
     a = findParent(a);
     b = findParent(b);

    if (a > b) parent[a] = parent[b];
    else parent[b] = a;
}

int main() {
    for (int i = 1; i < 1001; ++i) {
        parent[i] = i;
    }

    return 0;
}