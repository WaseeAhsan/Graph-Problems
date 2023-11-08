#include <bits/stdc++.h>
using namespace std;

const int N = 10000; 

vector<vector<int>> graph(N);
vector<bool> visited(N, false);

bool hasCycle(int vertex, int parent) {
    visited[vertex] = true;

    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            if (hasCycle(neighbor, vertex)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true; 
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m; // Number of nodes and edges

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool cycle = false;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (hasCycle(i, -1)) {
                cycle = true;
                break;
            }
        }
    }

    if (cycle) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}
