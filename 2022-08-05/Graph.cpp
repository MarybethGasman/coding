#include <assert.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> edges[], int v1, int v2) {
    edges[v1].push_back(v2);
#if defined(UNDIRECTED)

    edges[v2].push_back(v1);

#endif  // UNDIRECTED
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
bool hasEdge(vector<int> edges[], int n, int v1, int v2) {
    if (v1 >= n || v2 >= n) {
        return false;
    }
    return std::find(edges[v1].begin(), edges[v1].end(), v2) != edges[v1].end();
}
// random generate a graph with random quantity of edges
void generateGraph(vector<int> edges[], int n) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        edges[i].clear();
    }
    // at least one edge
    int edgeNum = rand() % n + 1;
    // assert(edgeNum != 0);
    for (int i = 0; i < edgeNum; i++) {
        int x = rand() % n;
        int y = (x + 1) % n;
        // assert(x != y);
        while (hasEdge(edges, n, x, y)) {
            x = rand() % n;
            y = (x + 1) % n;
        }
        addEdge(edges, x, y);
    }
}

// generate a directed complete graph (Toumament)
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
#include <list>
vector<int> DFSUtil(vector<int> g[], int v, bool visited[]) {
    // Mark the current node as visited and print it
    visited[v] = true;
    // cout << v << " ";
    vector<int> res;
    res.push_back(v);

    // Recur for all the vertices
    // adjacent to this vertex
    vector<int>::iterator i;
    for (i = g[v].begin(); i != g[v].end(); ++i)
        if (!visited[*i]) {
            vector<int> tmp = DFSUtil(g, *i, visited);
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
    return res;
}
// Method to print connected components in an
// undirected graph
vector<vector<int>> connectedComponents(vector<int> g[], int V) {
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    vector<vector<int>> result;
    for (int v = 0; v < V; v++)
        visited[v] = false;

    for (int v = 0; v < V; v++) {
        vector<int> tmp;
        if (visited[v] == false) {
            // print all reachable vertices
            // from v
            tmp = DFSUtil(g, v, visited);
            result.push_back(tmp);
        }
    }
    delete[] visited;
    return result;
}

// generate a undirected connected graph
void generateGraphUConnected(vector<int> edges[], int n) {
    srand((unsigned)time(NULL));
    // step 1: random generate a undirected graph
    generateGraph(edges, n);
    // step 2: make sure it is connected
    int v = rand() % n;
    vector<vector<int>> cc;
    // get connected Components
    cc = connectedComponents(edges, n);
    // add edge (v, c[index]) for each connected componet
    for (auto c : cc) {
        int index = rand() % c.size();
        while (c[index] == v || hasEdge(edges, n, v, c[index])) index = rand() % c.size();
        addEdge(edges, v, c[index]);
    }
}
// for undirected graph
void deleteEdge(vector<int> edges[], int v1, int v2) {
    vector<int>::iterator tmp;
    tmp = remove(edges[v1].begin(), edges[v1].end(), v2);
    edges[v1].erase(tmp);
    tmp = remove(edges[v2].begin(), edges[v2].end(), v1);
    edges[v2].erase(tmp);
}
// generate a undirected connected graph whose every vertice has an even degree
void generateGraphUconnectedEven(vector<int> edges[], int n) {
    // step 1: generate an undirected connected graph
    generateGraphUConnected(edges, n);

    vector<int> oddDegreeVertices;

    for (int i = 0; i < n; i++) {
        if (edges[i].size() & 1) {
            oddDegreeVertices.push_back(i);
        }
    }
    // note that every graph has even number of odd degree vertice
    // step 2: add or delete edge two by two
    while (!oddDegreeVertices.empty()) {
        // we can assume that there is at least two vertice in the contaienr
        int length = oddDegreeVertices.size();
        int x = oddDegreeVertices[length - 1];
        int y = oddDegreeVertices[length - 2];
        oddDegreeVertices.erase(oddDegreeVertices.end() - 2, oddDegreeVertices.end());
        if (hasEdge(edges, n, x, y)) {
            deleteEdge(edges, x, y);
        } else {
            addEdge(edges, x, y);
        }
    }
    // vector<vector<int>> cc = connectedComponents(edges, n);
    // int cclen = cc.size();
    // for (int i = 1; i < cclen; i++) {
    //     addEdge(edges,cc[i][0], cc[i - 1][0]);
    //     addEdge(edges,cc[i][0], cc[i - 1][1]);
    // }
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
    struct timespec begin;
    struct timespec end;

    srand((unsigned)time(NULL));
    // for (int i = 0; i < MAX_VERTICES_NUM; i++) {
    int n = 8;
    vector<int> g[n];
    vector<vector<int>> cb;
    generateGraphUconnectedEven(g, n);

    printVisualGraph(g, n);
    cb = connectedComponents(g, n);

    for (auto c : cb) {
        for (auto x : c) {
            cout << x << " ";
        }
        cout << endl;
    }
    assert(cb.size() == 1);

    for (int i = 0; i < n; i++) {
        printf("vertice %d has %lu edges\n", i, g[i].size());
        // assert(g[i].size() % 2 == 0);
    }

    // clock_gettime(CLOCK_MONOTONIC, &begin);
    // clock_gettime(CLOCK_MONOTONIC, &end);
    // printf("%d %llu\n", i, (unsigned long long)end.tv_nsec - begin.tv_nsec);

    return 0;
}