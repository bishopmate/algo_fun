#include<bits/stdc++.h>
/*
7
8
1 3
3 2
2 1
4 3
5 4
6 5
7 6
5 7
*/
using namespace std;
void dfs(int src, int par, map<int, set<int>>& gr, vector<pair<int, int>>& tout,vector<bool>& vis, int& timer){
  if(!vis[src])
    vis[src] = true;
  for(auto x: gr[src]){
    if(x != par && !vis[x]){
      dfs(x, src, gr, tout, vis, timer);
    }
  }
  tout.push_back(make_pair(++timer, src));
}

void simpleDFS(int src, int par, map<int, set<int>>& tGr, vector<bool>& vis, vector<int>& scc){
  if(!vis[src]){
    vis[src] = true;
    scc.push_back(src);
  }
  for(auto x: tGr[src]){
    if(x != par && !vis[x]){
      simpleDFS(x, src, tGr, vis, scc);
    }
  }
  tGr.erase(tGr.find(src));
}
int main(){
  int n;  cin>>n;
  int m;  cin>>m;
  map<int, set<int>> gr, tGr;
  for(int i=0; i<m; i++){
    int x,y;
    cin>>x>>y;
    gr[x].insert(y);
    tGr[y].insert(x);
  }
  vector<pair<int, int>> tout;
  int timer = 0;
  vector<bool> vis(n+1);
  for(int i=1; i<= n; i++){
    if(!vis[i]){
      dfs(i, i, gr, tout, vis, timer);
    }
  }
  for(int i=1; i<=n; i++) vis[i] = false;
  sort(tout.begin(), tout.end(), greater<pair<int, int>>());
  vector<int> scc;
  vector<vector<int>> sccs;
  while(!tout.empty()){
    pair<int, int> x = *(tout.begin());
    if(!vis[x.second]){
      if(scc.size() > 0){
        sccs.push_back(scc);
        scc.clear();
      }
      simpleDFS(x.second, x.second, tGr, vis, scc);
    }
    tout.erase(tout.begin());
  }
  if(scc.size() > 0){
        sccs.push_back(scc);
  }
  cout<<"There are "<<sccs.size()<<" SCCs in the graph \n";
  for(auto x:sccs){
    for(auto y:x){
      cout<<y<<" ";
    }
    cout<<endl;
  }
  return 0;
}