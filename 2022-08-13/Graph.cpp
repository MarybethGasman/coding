#include <assert.h>

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// directed Graph
void addEdge(vector<pair<int, int>> edges[], int v1, int v2, int weight) {
    edges[v1].push_back(make_pair(v2, weight));

    // edges[v2].push_back(v1);
}
void printGraph(vector<pair<int, int>> edges[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (auto x : edges[i]) {
            cout << x.first << " -> ";
        }
        cout << endl;
    }
}
void printVisualGraph(vector<pair<int, int>> edges[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i << endl;
    }
    for (int i = 0; i < n; i++) {
        for (auto x : edges[i]) {
            cout << i << " " << x.first << " " << x.second << endl;
        }
    }
}
bool hasEdge(vector<pair<int, int>> edges[], int n, int v1, int v2) {
    if (v1 >= n || v2 >= n) {
        return false;
    }

    for (auto x : edges[v1]) {
        if (x.first == v2) return true;
    }
    return false;
}
// random generate a graph with random quantity of edges
void generateGraph(vector<pair<int, int>> edges[], int n) {
    for (int i = 0; i < n; i++) {
        edges[i].clear();
    }
    // at least one edge
    int edgeNum = rand() % n * 2;
    // assert(edgeNum != 0);
    for (int i = 0; i < edgeNum; i++) {
        int x = rand() % n;
        int y = rand() % n;

        while (hasEdge(edges, n, x, y)) {
            x = rand() % n;
            y = (x + 1) % n;
        }
        int randweight = rand() % 200 - 100;
        addEdge(edges, x, y, randweight);
    }
}

int main() {
    srand((unsigned)time(NULL));
    int n = 8;
    vector<pair<int, int>> g[n];
    generateGraph(g, n);
    printVisualGraph(g, n);

    return 0;
}