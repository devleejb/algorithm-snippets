#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, pair<int, int> > > edges;
int parent[8];
int sum;

int find_parent(int x) {
    if (parent[x] != x) parent[x] = find_parent(parent[x]);

    return parent[x];
}

void union_set(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    if (a > b) parent[a] = parent[b];
    else parent[b] = parent[a];
}

void kruskal() {
    for (int i = 0; i < edges.size(); ++i) {
        int cost = edges[i].first;
        int start = edges[i].second.first;
        int end = edges[i].second.second;

        if (find_parent(start) != find_parent(end)) {
            union_set(start, end);
            sum += cost;
        }
    }
}

int main() {
    // Initialize Parent
    for (int i = 1; i < 8; ++i) {
        parent[i] = i;
    }

    // Input Eges
    edges.push_back(make_pair(29, make_pair(1, 2)));
    edges.push_back(make_pair(35, make_pair(2, 3)));
    edges.push_back(make_pair(7, make_pair(3, 4)));
    edges.push_back(make_pair(13, make_pair(4, 7)));
    edges.push_back(make_pair(25, make_pair(6, 7)));
    edges.push_back(make_pair(53, make_pair(5, 6)));
    edges.push_back(make_pair(75, make_pair(1, 5)));
    edges.push_back(make_pair(34, make_pair(2, 6)));
    edges.push_back(make_pair(23, make_pair(4, 6)));

    // Sort Edges
    sort(edges.begin(), edges.end());

    kruskal();

    printf("%d", sum);

    return 0;
}