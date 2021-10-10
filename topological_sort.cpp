#include <stdio.h>
#include <queue>
#include <vector>

#define N 7 // num of nodes
#define E 8 // num of edges

using namespace std;

vector<int> edges[8];
int indegree[8];

void topologicalSort() {
    queue<int> q;
    
    for (int i = 1; i < 8; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        printf("%d ", now);

        for (int i = 0; i < edges[now].size(); ++i) {
            if (--indegree[edges[now][i]] == 0) {
                q.push(edges[now][i]);
            }
        }
    }
}

int main() {
    // Input Edges
    edges[1].push_back(2);
    edges[1].push_back(5);
    edges[2].push_back(3);
    edges[2].push_back(6);
    edges[3].push_back(4);
    edges[4].push_back(7);
    edges[5].push_back(6);
    edges[6].push_back(4);

    indegree[1] = 0;
    indegree[2] = 1;
    indegree[3] = 1;
    indegree[4] = 2;
    indegree[5] = 1;
    indegree[6] = 2;
    indegree[7] = 1;

    topologicalSort();

    return 0;
}