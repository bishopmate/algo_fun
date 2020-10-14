#include<bits/stdc++.h>
using namespace std;
/*
Sample Input
6 9
2 1 2
4 1 3
3 1 4
6 2 5
1 3 5
2 3 4
5 3 6
4 5 6
4 4 6

Sample Output
3 5 Weight - 1
1 2 Weight - 2
3 4 Weight - 2
1 4 Weight - 3
4 6 Weight - 4
*/

class DSU{
    map<int, int> parent;
    map<int, int> rank;
public:
    int find_set(int a){
        if(parent[a]!=a){
            parent[a] = find_set(parent[a]);    // Path Compression Optimization
            return parent[a];
        }
        return a;
    }

    void make_set_by_rank(int v){
        parent[v] = v;
        rank[v] = 0;
    }

    void union_sets_by_rank(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a!=b){
            if(rank[a]<rank[b]){
                swap(a,b);
            }
            parent[b] = a;
            if(rank[a]==rank[b])
                rank[a]++;
        }
    }
};

int main(){
  int n,m;
  cin>>n>>m;
  vector<pair<int, pair<int, int>>> edges;
  for(int i=0; i<m; i++){
    int w,x,y;
    cin>>w>>x>>y;
    edges.push_back(make_pair(w, make_pair(x,y)));
  }
  DSU tree;
  for(int i=1; i<=n; i++){
    tree.make_set_by_rank(i);
  }
  sort(edges.begin(), edges.end());
  vector<pair<int, pair<int, int>>> MST;
  int edgesInMST = 0;
  int i = 0;
  int costMST = 0;
  while(i < m && edgesInMST < (n-1)){
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    int uGroup = tree.find_set(u), vGroup = tree.find_set(v);
    if(uGroup != vGroup){
      tree.union_sets_by_rank(u,v);
      costMST = costMST + edges[i].first;
      MST.push_back(edges[i]);
      edgesInMST++;
    }
    i++; 
  }
  for(auto edgeMST : MST){
    cout<<edgeMST.second.first<<" "<<edgeMST.second.second<<" Weight - "<<edgeMST.first<<"\n";
  }
  return 0;
}
