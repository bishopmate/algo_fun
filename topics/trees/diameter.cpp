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

The algorithm that I followed is as below:
1) Pick any node as root.
2) Perform a BFS from the chosen root.
3) Pick the farthest node from the previous root as your new root(This new root will also be one of the end points of your Diameter).
4) Perform a BFS from the new Root and the farthest node from this new Root is our second end Point of the Diameter.
5) Trace the diameter with the help of Parent Array from the second end Point that we just found backwards.

I would suggest to perform a DRY run with pen and paper with an example(You can always choose the Sample Input Provided) to understand
this Algorithm even better and why it works.
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
