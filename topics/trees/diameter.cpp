#include<bits/stdc++.h>
using namespace std;
/*
Sample Input
10 9
1 2
2 3
2 4
1 5
1 9
5 6
5 8
6 7
9 10
Sample Output
Diameter's length is 5
The diameter is -> 3-2-1-5-6-7
*/
void bfs(int src, int parent, int parents[], int distance[],bool visited[], map<int, vector<int>>& graph){
  queue<int> q;
  q.push(src);
  parents[src] = parent;
  visited[src] = true;
  distance[src] = 0;
  while(!q.empty()){
    int u = q.front();
    q.pop();

    for(auto v:graph[u]){
      if(!visited[v]){
        q.push(v);
        visited[v] = true;
        distance[v] = distance[u]+1;
        parents[v] = u;
      }
    }

  }

}
int main(){
  int vertices,edges;
  cin>>vertices>>edges;
  map<int, vector<int>> graph;
  for(int i=0; i<edges; i++){
    int u,v;
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int parents[vertices+1];
  bool visited[vertices+1];
  int distance[vertices+1];
  memset(visited, false, sizeof(visited));
  memset(distance,0, sizeof(distance));
  for(int i=1; i<=vertices; i++){
    if(!visited[i])
      bfs(i,i,parents,distance,visited,graph);
  }
  int newSource = 1;
  int helper = 0;
  for(int i=1; i<=vertices; i++){
    if(distance[i] > helper){
      helper = distance[i];
      newSource = i;
    }
  }
  memset(visited, false, sizeof(visited));
  memset(distance,0, sizeof(distance));
  
  bfs(newSource, newSource, parents, distance, visited, graph);
  vector<int> diameter;
  int diameterEnd = newSource;
  helper = 0;
  for(int i=1; i<=vertices; i++){
    if(distance[i] > helper){
      helper = distance[i];
      diameterEnd = i;
    }
  }
  helper = diameterEnd;
  while(parents[helper] != helper){
    diameter.push_back(helper);
    helper = parents[helper];
  }
  diameter.push_back(helper);
  int diameterLength = diameter.size()-1;
  cout<<"Diameter's length is "<<diameterLength<<endl;
  cout<<"The diameter is -> ";
  for(int i=0; i<=diameterLength; i++){
    cout<<diameter[i];
    if(i != diameterLength)
      cout<<"-";
  }
  
  return 0;
}