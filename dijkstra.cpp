#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>

#define INF 123456789

using namespace std;

vector<pair<int, int> > edges[7];
int isVisited[7], d[7];

void dijkstra(int start) {
    int nowVer, nowDis;
    priority_queue<pair<int, int> > pq;

    for (int i = 1; i < 7; ++i) {
        d[i] = INF;
    }

    d[start] = 0;

    pq.push(make_pair(0, 1));

    while (!pq.empty()) {
        nowVer = pq.top().second;
        nowDis = -pq.top().first;

        pq.pop();

        isVisited[nowVer] = 1;

        if (d[nowVer] > nowDis) continue;

        for (int i = 0; i < edges[nowVer].size(); ++i) {
            int toVertex = edges[nowVer][i].second;
            int toVertexCost = d[nowVer] - edges[nowVer][i].first;

            if (toVertexCost < d[toVertex] && isVisited[toVertex] == 0) {
                d[toVertex] = toVertexCost;

                pq.push(make_pair(-toVertexCost, toVertex));
            }
        }
    }
}

int main() {
    // make graph
    edges[1].push_back(make_pair(-2, 2));
    edges[1].push_back(make_pair(-1, 4));
    edges[2].push_back(make_pair(-2, 4));
    edges[2].push_back(make_pair(-3, 3));
    edges[3].push_back(make_pair(-3, 2));
    edges[3].push_back(make_pair(-5, 6));
    edges[4].push_back(make_pair(-3, 3));
    edges[4].push_back(make_pair(-1, 5));
    edges[5].push_back(make_pair(-1, 3));
    edges[5].push_back(make_pair(-2, 6));

    dijkstra(1);

    for (int i = 1; i < 7; ++i) {
        printf("Shortest Distance to Vertex %d : %d\n", i, d[i]);
    }

    return 0;
}