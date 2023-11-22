#include <bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);

#define ll long long

#define endl "\n"
#define sort0(v) sort(all(v))

#define N 1000007
using namespace std;

int n, m;
vector<string> ed;
bool vis[1001][1001];
int fx[] = {1, -1, 0, 0, 1, -1, 1, -1}; 
int fy[] = {0, 0, 1, -1, 1, -1, -1, 1};

bool valid(int i, int j) {
    if (vis[i][j] == 1) return false;
    if (i >= 0 && i < n && j >= 0 && j < m) {
        return true;
    }
    return false;
}

void dfs(int i, int j) {
    vis[i][j] = 1;

    for (int k = 0; k < 8; k++) {
        int tx = i + fx[k];
        int ty = j + fy[k];
        if (valid(tx, ty) && ed[tx][ty] == '@') {
            dfs(tx, ty);
        }
    }
}
/*
void solve() {
    cin >> n >> m;

        if( m == 0)
        return ; 

    ed.clear();
    memset(vis, 0, sizeof(vis));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ed.push_back(s);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]==0  and ed[i][j] == '@') {
                dfs(i, j);cnt++;
                
            }
        }
    }

    cout << cnt << endl;
}
*/

int main() {
    int t = 1;
    // cin >> t;
    while (1) {
       // solve();

        cin >> n >> m;
                if(m == 0 ) break; 
      

    ed.clear();
    memset(vis, 0, sizeof(vis));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ed.push_back(s);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]==0  and ed[i][j] == '@') {
                dfs(i, j);cnt++;
                
            }
        }
    }

    cout << cnt << endl;
    }

    return 0;
}
