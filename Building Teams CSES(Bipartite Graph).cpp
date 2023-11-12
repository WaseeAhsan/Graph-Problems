#include <bits/stdc++.h>
#include <vector>
#include <list>
using namespace std;

int n, m;
vector<int> color(100001);
vector<bool> vis;
vector<int> g[200005];

bool dfs(int u, int c, int par) {
    vis[u] = true;
    color[u] = c;

    for (auto v : g[u]) {
        if (v == par)
            continue;

        if (color[v] == 0) {
            if (!dfs(v, (color[u] ^ 3), u))
                return false;
        }
        if (color[v] == color[u])
            return false;
    }
    return true;
}

bool color_all() {
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (!dfs(i, 1, 0))
                return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vis.assign(n + 1, false);

    if (color_all()) {

      for(int i = 1 ; i <= n ;i++){
         cout << color[i] << " " ; 
      }

    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
