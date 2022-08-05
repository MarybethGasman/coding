#include <assert.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> edges[], int v1, int v2) {
    edges[v1].push_back(v2);
    // edges[v2].push_back(v1);
}
void printGraph(vector<int> edges[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (auto x : edges[i]) {
            cout << x << " -> ";
        }
        cout << endl;
    }
}
void printVisualGraph(vector<int> edges[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i << endl;
    }
    for (int i = 0; i < n; i++) {
        for (auto x : edges[i]) {
            cout << i << " " << x << endl;
        }
    }
}
void generateGraph(vector<int> edges[], int n) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        edges[i].clear();
    }
    int edgeNum = rand() % n + 1;
    assert(edgeNum != 0);
    for (int i = 0; i < edgeNum; i++) {
        int x = rand() % n;
        int y = rand() % n;
        addEdge(edges, x, y);
    }
}
bool hasEdge(vector<int> edges[], int n, int v1, int v2) {
    if (v1 >= n || v2 >= n) {
        return false;
    }
    return std::find(edges[v1].begin(), edges[v1].end(), v2) != edges[v1].end();
}
void generateGraphDC(vector<int> edges[], int n) {
    srand((unsigned)time(NULL));
    int edgeNum = n * (n - 1) / 2;

    for (int i = 0; i < n; i++) {
        edges[i].clear();
    }
    for (int i = 0; i < edgeNum; i++) {
        int x = rand() % n;
        int y = rand() % n;
        while (x == y || hasEdge(edges, n, x, y) || hasEdge(edges, n, y, x)) {
            x = rand() % n;
            y = rand() % n;
        }
        addEdge(edges, x, y);
    }
}
void generateGraphC(vector<int> edges[], int n) {
    for (int i = 0; i < n; i++) {
        edges[i].clear();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) addEdge(edges, i, j);
        }
    }
}
vector<int> HPForToumament(vector<int> edges[], int n) {
    //输入的图必须是Toumament
    vector<int> hp;
    if (n) hp.push_back(0);
    for (int i = 1; i < n; i++) {
        if (hasEdge(edges, n, i, hp[0])) {
            hp.insert(hp.begin(), i);
        } else if (hasEdge(edges, n, hp[hp.size() - 1], i)) {
            hp.insert(hp.end(), i);
        } else {
            int j = 0;
            while (!hasEdge(edges, n, i, hp[j])) j++;
            hp.insert(hp.begin() + j, i);
        }
    }
    return hp;
}

#define MAX_VERTICES_NUM 100
int main() {
#if defined(VERIFY)
    int n = 1000;
    vector<int> g[n];
    generateGraphDC(g, n);

    // printVisualGraph(g, n);

    vector<int> hp = HPForToumament(g, n);
    assert((int)hp.size() == n);
    for (size_t i = 0; i < hp.size() - 1; i++) {
        assert(hasEdge(g, n, hp[i], hp[i + 1]));
        assert(hp[i] != hp[i + 1]);
    }
    printf("Accept!\n");

#endif  // VERIFY
    struct timespec begin;
    struct timespec end;
    for (int i = 0; i < MAX_VERTICES_NUM; i++) {
        int n = i;
        vector<int> g[n];
        generateGraphDC(g, n);

        // printVisualGraph(g, n);


        clock_gettime(CLOCK_MONOTONIC, &begin);
        vector<int> hp = HPForToumament(g, n);
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("%d %llu\n", i, (unsigned long long)end.tv_nsec - begin.tv_nsec);

        assert((int)hp.size() == n);
        for (int i = 1; i < (int)hp.size() - 1; i++) {
            assert(hasEdge(g, n, hp[i], hp[i + 1]));
            assert(hp[i] != hp[i + 1]);
        }
        // printf("Accept!\n");
    }

    return 0;
}