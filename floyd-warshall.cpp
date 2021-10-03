#include <stdio.h>
#include <algorithm>

#define INF 1000

using namespace std;

int weight[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 0, 4, INF, 6},
    {0, 3, 0, 7, INF},
    {0, 5, INF, 0, 4},
    {0, INF, INF, 2, 0}
};

void floydWarshall(int numOfVertices) {
    for (int dep = 1; dep <= numOfVertices; ++dep) {
        for (int des = 1; des <= numOfVertices; ++des) {
            for (int i = 1; i <= numOfVertices; ++i) {
                if (weight[dep][des] > weight[dep][i] + weight[i][des]) {
                    weight[dep][des] = weight[dep][i] + weight[i][des];
                }
            }
        }
    }
}

int main() {
    floydWarshall(4);

    for (int dep = 1; dep <= 4; ++dep) {
        for (int des = 1; des <= 4; ++des) {
            printf("%d ", weight[dep][des]);
        }

        printf("\n");
    }
    
    return 0;
}