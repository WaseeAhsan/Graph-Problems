#include <bits/stdc++.h>
#define WaseeAhasn ios_base::sync_with_stdio(0);cin.tie(0);

#define ll long long

#define endl "\n"
#define sort0(v) sort(all(v))

#define N 1000007
using namespace std;



vector<int>dsuf ; 

int find(int v)
{
        if(dsuf[v]== -1)
        {
                return v ;
        }
        return find(dsuf[v]) ; 
}

void union_op(int fromp ,int top)
{
        fromp = find(fromp);  
        top = find(top) ; 
        dsuf[fromp] = top ; 
}


bool isCyclic (vector<pair<int,int>>& edge_list)
{
        for(auto p : edge_list)
        {
                int fromp = find(p.first) ; 
                int top = find(p.second) ; 

                if(fromp == top)
                return true ; 

                union_op(fromp,top) ; 
        }
}

int main()
{               
                // Detect cycle in an Undirected Graph 
                /* Node 0  1  2  3 
                parent -1 -1 -1 -1
                  
                */

                WaseeAhasn;
                
                int e , v ; 
                cin >> e >> v  ; 
                dsuf.resize(v,-1) ; 

                vector<pair<int,int>>edge_list ; 
                for(int i = 0 ; i < e ; i++)
                {
                        int from,to ; 
                        cin  >> from >> to ; 
                        edge_list.push_back({from,to}) ; 
                }



              if(isCyclic(edge_list))
              {
                cout << "True\n" ; 
              }
              else{
                cout << "No\n"  ; 
              }
                
              

 return 0;
}