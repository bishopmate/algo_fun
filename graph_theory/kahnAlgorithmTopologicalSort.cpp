#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  int m;cin>>m;
  map<int,vector<int>> gr;
  vector<int> indegree(n,0);
  for(int i=0; i<m; i++){
    int x,y;
    cin>>x>>y;
    gr[x].push_back(y);
    indegree[y]++;
  }
  
  queue<int> q;
  for(int i=0; i<n; i++)
    if(indegree[i] == 0)
      q.push(i);
  
  vector<int> sorted;
  while (!q.empty()){
    int cur = q.front();
    q.pop();
    sorted.push_back(cur);
    for(auto neighbor : gr[cur]){
      indegree[neighbor]--;
      if(indegree[neighbor] == 0)
        q.push(neighbor);
    }
  }
  for(auto node : sorted){
    cout<<node<<" ";
  }
  cout<<endl;
  return 0;
}
/*
Input
6
5 2
5 0
4 0
4 1
2 3
3 1
Output
4 5 2 0 3 1
*/
