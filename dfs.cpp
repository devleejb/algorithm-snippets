#include <stdio.h>
#include <vector>

using namespace std;

vector<int> graph[7];
int visited[7];

void dfs(int vertex) {
    printf("%d\n", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < graph[vertex].size(); ++i) {
        int toVertex = graph[vertex][i];

        if (visited[toVertex] == 0) {
            dfs(toVertex);
        }
    }
}

int main() {
    // Make Graph
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[0].push_back(3);

    graph[1].push_back(0);

    graph[2].push_back(0);
    graph[2].push_back(4);
    graph[2].push_back(5);
    
    graph[3].push_back(0);
    graph[3].push_back(6);

    graph[4].push_back(2);
    
    graph[5].push_back(2);
    
    graph[6].push_back(3);

    // Execute DFS
    dfs(0);
    
    return 0;
}