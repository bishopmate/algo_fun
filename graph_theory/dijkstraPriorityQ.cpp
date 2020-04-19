#include<bits/stdc++.h>
#define ll long long


using namespace std;
void dijkstra(vector<vector<pair<ll,ll>>> edge, vector<ll>& D){
    
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,0});
    D[0] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(auto x:edge[u]){
            int v = x.first, cost = x.second;
            if(D[v] > D[u]+cost){
                D[v] = D[u] + cost;
                pq.push({D[v], v});
            }            
        }
    }



}

int main(){
    ll v,e,a,b,w;
    cin>>v>>e;
    vector<vector<pair<ll,ll>>> edge(e+1);
    vector<ll> D(v,987654321);
    while(e--){
        cin>>a>>b>>w;
        edge[a].push_back({b,w});
        edge[b].push_back({a,w});
    }
    dijkstra(edge, D);  
    for(int i=0;i<v;++i){
        cout<<D[i]<<" ";
    }
    return 0;
}
