#include<bits/stdc++.h>

#define endl cout<<"\n" 
#define ll long long

using namespace std;


void debug(vector<ll> x){
    for(auto e:x){
        cout<<e<<" ";
    }
    endl;
}

ll dfsToCalculateSizes(vector<vector<ll>>& graph, ll u, ll v, vector<ll>& sizes){
    sizes[u] = 1;// counting itself
    for(auto x: graph[u]){
        if(x==v)    continue;
        sizes[u] += dfsToCalculateSizes(graph, x, u, sizes);    
    }
    return sizes[u];
}

void dfsToCalculateDepths(vector<vector<ll>>& graph, ll u, ll v, vector<ll>& depths){
    depths[u] = depths[v] + 1;
    for(auto x: graph[u]){
        if(x==v)    continue;
        dfsToCalculateDepths(graph, x, u, depths);
    }
    return ;    
}

void solve(){
    
    ll n,k,x,y;
    cin>>n>>k;
    vector<vector<ll>> graph(n+1);
    vector<ll> sizes(n+1, 0);
    vector<ll> depths(n+1, -1);
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x); // comment for directed graph case
    }
    // for(int i=1; i<=n; i++){
    //     cout<<i<<"   - ";
    //     for(auto x: graph[i]){
    //         cout<<x<<" ";
    //     }
    //     endl;
    // }

    x = dfsToCalculateSizes(graph, 1, 0, sizes);// This is a reverse dfs
    for(auto x:sizes){
        cout<<x<<" ";
    }
    endl;
    dfsToCalculateDepths(graph, 1, 0, depths);
    for(auto x:depths){
        cout<<x<<" ";
    }
    endl;

}
signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}

/*
Sample Input
8 5
7 5
1 7
6 1
3 7
8 3
2 1
4 5
Sample Output
0 8 1 2 1 2 1 5 1 
-1 0 1 2 3 2 1 1 3 
*/
