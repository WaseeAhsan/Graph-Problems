#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 3;
const ll inf = 1e18;

vector<vector<pair<int, int>>> graph(N, vector<pair<int, int>>());
vector<ll> lev(N, inf);

int main() {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int x, y, wt;
        cin >> x >> y >> wt;

        graph[x].push_back({wt, y});
        // graph[y].push_back({x, wt}); // Uncomment this line if the graph is undirected
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    pq.push({0, 1});
    lev[1] = 0;

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (lev[u] < d)
            continue;

        for (auto e : graph[u]) {
            int v = e.second;
            int c = e.first;

            if (lev[v] <= c + d) {
                continue;
            } else {
                lev[v] = c + d;
                pq.push({lev[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << lev[i] << " ";
    cout << endl;

    return 0;
}
