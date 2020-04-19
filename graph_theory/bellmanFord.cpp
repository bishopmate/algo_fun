#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

void bellmanFord(vector<vector<pair<ll,ll>>> edges, vector<ll>& D){
    int v = D.size();
    int src = 0;
    D[0] = 0;
    for(ll i=0;i<v;++i){
        
        for(ll u=0;u<v;++u){
            
            for(auto v:edges[u]){
                ll d = v.first;
                if(D[d] > D[u]+v.second){
                    D[d] = D[u] + v.second;
                    // cout<<D[d]<<" = "<<D[u]<<" + "<<v.second<<"\n";
                } 
            }

        }
    }
    // To check a negative cycle
    bool negative = true;
    for(ll u=0;u<v;++u){
            
            for(auto v:edges[u]){
                ll d = v.first;
                if(D[d] > D[u]+v.second){
                    D[d] = D[u] + v.second;
                }
                if(D[d]>=0)
                    negative = false;
            }

    }

    if(negative)
        cout<<"Negative Cycle Exists\n";
    
    return;
}

int main(){
    ll v,e;
    cin>>v>>e;
    vector<vector<pair<ll,ll>>> edges(v);
    ll a,b,w;
    for(ll i=0; i<e; ++i){
        cin>>a>>b>>w;
        edges[a].pb({b,w});
    }
    vector<ll> D(v);
    for(ll i=0; i<v; ++i){
        D[i] = 987654321;
    }
    bellmanFord(edges, D);
    for(ll i=0; i<v; ++i){
        cout<<D[i]<<" ";
    }
    cout<<endl;
    return 0;
}