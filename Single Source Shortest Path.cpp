#include<bits/stdc++.h>
using namespace std  ;

const int N = 1e5 + 10 ; 



vector<int>adj[N] ; 
vector<int>visited ; 
vector<int>dist  ; 

void BFS(int source)
{
     dist[source] = 0 ; 
    queue<int>q ; 
    q.push(source) ; 

    while (!q.empty())
    {
        int curr = q.front() ; 
        q.pop() ; 

        if(visited[curr])
        {
            continue;
            
        }

        visited[curr]  = true ; 

        for(auto i : adj[curr])
        {
            if(dist[curr] + 1 < dist[i])
            {
                dist[i] = dist[curr] +  1 ; 
                q.push(i) ; 
            }
        }


    }
    


}

int main()
{

    int n , m ; cin >> n >> m ; 

    for(int i = 0 ; i <= n ; i++)
    {
        adj[i].clear(); 
    }

    visited.assign(n + 2 , false ) ; 

    dist.assign(n + 2 , INT_MAX);

    for(int i = 0 ; i < m ; i++)
    {
        int u , v ; cin >> u >> v ; 
        adj[u].push_back(v); 
        adj[v].push_back(u) ; 
    }
   
    

    BFS(1) ; 

    for(int i = 1 ; i <= n  ; i++)
    {
        cout << dist[i]<< " " ;
    }
    cout << endl ;


    return 0 ;
}