#include<bits/stdc++.h>
#define ll long long 
using namespace std; 

vector<int>tree[200001] ; 

void dfs(int curr , int prev , int count[])
{
    count[curr] = 1 ;
    for(auto nbr : tree[curr] )
    {
        dfs(nbr, curr, count) ; 
        count[curr] += count[nbr] ; 
    }
}


int main()
{
    int n ; cin >> n ; 
   int emp[n-1] ; 

   for(int i = 0 ; i < n- 1 ;i++)
    {int x  ; cin >> x ; 
        //cin >> emp[i] ; 
        tree[x].push_back(i+2) ; 
    }

    int count[n+1] ; 

    dfs(1 , 0 ,  count) ; 

    for(int i = 1 ; i<= n  ;i++){
        cout << count[i] -1 << " " ;
    }
    cout << endl ; 



  

}
