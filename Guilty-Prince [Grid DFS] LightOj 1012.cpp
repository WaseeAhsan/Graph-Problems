#include <bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int n, m, cnt;
vector<string> ed;
bool vis[21][21];
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && ed[i][j] != '#');
}

void dfs(int i, int j) {
    vis[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int tx = i + fx[k];
        int ty = j + fy[k];
        if (valid(tx, ty)) {
            cnt++; 
            dfs(tx, ty);
        }
    }
}

int main() {
    int t;
    cin >> t;
    int k  = 1  ;
    while (t--) {
        cnt = 0;
        cin >> m >> n ;

        ed.clear();
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            ed.push_back(s);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && ed[i][j] == '@') {
                    cnt++; 
                    dfs(i, j);
                    break; // Exit the loop after finding the initial position '@'
                }
            }
        }

        cout <<"Case "<< k++ << ": " <<cnt << endl;
       
    }

    return 0;
}
