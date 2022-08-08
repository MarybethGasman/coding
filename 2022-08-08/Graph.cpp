#include <assert.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// Undirected Graph
void addEdge(vector<int> edges[], int v1, int v2) {
    edges[v1].push_back(v2);

    edges[v2].push_back(v1);
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
// A recursive function that
// uses visited[] and parent to detect
// cycle in subgraph reachable
// from vertex v.
bool isCyclicUtil(vector<int> g[], int v, bool visited[], int parent) {
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices
    // adjacent to this vertex
    vector<int>::iterator i;
    for (i = g[v].begin(); i != g[v].end(); ++i) {
        // If an adjacent vertex is not visited,
        // then recur for that adjacent
        if (!visited[*i]) {
            if (isCyclicUtil(g, *i, visited, v))
                return true;
        }

        // If an adjacent vertex is visited and
        // is not parent of current vertex,
        // then there exists a cycle in the graph.
        else if (*i != parent)
            return true;
    }
    return false;
}

// Returns true if the graph contains
// a cycle, else false.
bool isCyclic(vector<int> g[], int n) {
    // Mark all the vertices as not
    // visited and not part of recursion
    // stack
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    // Call the recursive helper
    // function to detect cycle in different
    // DFS trees
    for (int u = 0; u < n; u++) {
        // Don't recur for u if
        // it is already visited
        if (!visited[u])
            if (isCyclicUtil(g, u, visited, -1))
                return true;
    }
    return false;
}
#include <cstring>
// This function removes edge u-v from graph.  It removes
// the edge by replacing adjacent vertex value with -1.
void rmvEdge(vector<int> g[], int u, int v) {
    // Find v in adjacency list of u and replace it with -1
    vector<int>::iterator iv = find(g[u].begin(), g[u].end(), v);
    *iv = -1;

    // Find u in adjacency list of v and replace it with -1
    vector<int>::iterator iu = find(g[v].begin(), g[v].end(), u);
    *iu = -1;
}
// A DFS based function to count reachable vertices from v
int DFSCount(vector<int> g[], int v, bool visited[]) {
    // Mark the current node as visited
    visited[v] = true;
    int count = 1;

    // Recur for all vertices adjacent to this vertex
    vector<int>::iterator i;
    for (i = g[v].begin(); i != g[v].end(); ++i)
        if (*i != -1 && !visited[*i])
            count += DFSCount(g, *i, visited);

    return count;
}
// The function to check if edge u-v can be considered as
// next edge in Euler Tout
bool isValidNextEdge(vector<int> g[], int n, int u, int v) {
    // The edge u-v is valid in one of the following two
    // cases:

    // 1) If v is the only adjacent vertex of u
    int count = 0;  // To store count of adjacent vertices
    vector<int>::iterator i;
    for (i = g[u].begin(); i != g[u].end(); ++i)
        if (*i != -1)
            count++;
    if (count == 1)
        return true;

    // 2) If there are multiple adjacents, then u-v is not a
    // bridge Do following steps to check if u-v is a bridge

    // 2.a) count of vertices reachable from u
    bool visited[n];
    memset(visited, false, n);
    int count1 = DFSCount(g, u, visited);

    // 2.b) Remove edge (u, v) and after removing the edge,
    // count vertices reachable from u
    deleteEdge(g, u, v);
    memset(visited, false, n);
    int count2 = DFSCount(g, u, visited);

    // 2.c) Add the edge back to the graph
    addEdge(g, u, v);

    // 2.d) If count1 is greater, then edge (u, v) is a
    // bridge
    return (count1 > count2) ? false : true;
}
// Print Euler tour starting from vertex u
void printEulerUtil(vector<int> g[], int n, int u) {
    // Recur for all the vertices adjacent to this vertex
    vector<int>::iterator i;
    for (i = g[u].begin(); i != g[u].end(); ++i) {
        int v = *i;

        // If edge u-v is not removed and it's a a valid
        // next edge
        if (v != -1 && isValidNextEdge(g, n, u, v)) {
            cout << u << "-" << v << "  ";
            rmvEdge(g, u, v);
            printEulerUtil(g, n, v);
        }
    }
}
void printEulerTour(vector<int> g[], int n) {
    // Find a vertex with odd degree
    int u = 0;
    for (int i = 0; i < n; i++)
        if (g[i].size() & 1) {
            u = i;
            break;
        }

    // Print tour starting from oddv
    printEulerUtil(g, n, u);
    cout << endl;
}

// vector<int> eulerCycleUtil(vector<int> g[], int v, int parent) {

// }

// vector<int> eulerCycle(vector<int> g[], int n) {
//     // assume the graph g is connected and every vertice has even degree
//     vector<pair<int, int>> G[n];
//     for (int i = 0; i < n; i++) {
//         for (auto x : g[i]) {
//             G[i].push_back(make_pair(x, 0));
//         }
//     }
//     vector<int> ec;
//     ec.push_back(0);
//     for (int i = 1; i < n; i++) {

//     }
// }

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
    printEulerTour(g, n);
    // clock_gettime(CLOCK_MONOTONIC, &begin);
    // clock_gettime(CLOCK_MONOTONIC, &end);
    // printf("%d %llu\n", i, (unsigned long long)end.tv_nsec - begin.tv_nsec);

    return 0;
}