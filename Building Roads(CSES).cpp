
#include<bits/stdc++.h>
using namespace std;
int N = 1e5;
vector<vector<int>> vc;
vector<int> lev;
int countOnes(const std::vector<int>& vec) {
    int count = 0;
    for (int element : vec) {
        if (element == 1) {
            count++;
        }
    }
    return count;
}

int main(){
    int n,m; cin>>n>>m;

    vc.clear(), lev.clear();
    vc.resize(n+1) , lev.resize(n+1);

    for(int i=0; i<m; i++){
        int x,y;  cin>>x>>y;

        vc[x].push_back(y);
        vc[y].push_back(x);
    }

    for(int i  = 1 ; i <= n ;i++){ 
    queue<int> q;
    if(lev[i] == 0 ){
    q.push(i), lev[i]= 1;
    }

    while(!q.empty() ){
        int val = q.front();
        q.pop();

        for(auto child: vc[val]){
            
            if(lev[child]==0){
                q.push(child);
                lev[child] = lev[val] +1;
            }
        }
    }
    }
         int onesCount = countOnes(lev);
         cout << onesCount - 1 << endl ; 
    for(int i=1; i<=n; i++){
        //cout<<lev[i]<<" "; 
        if(i != 1 && lev[i] == 1){
                    cout << i - 1 << " " << i  << endl ; 
        }
    }

    cout<<endl;


}
