#include<iostream>
#include<map>
#include<list>
#include<typeinfo>
#include<queue>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T>> adjList;
public:
    Graph(){

    }
    
    void addEdge(T u, T v, bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }

    }
    // Check for undirected graph
    bool isCyclicBFS(T src){
        map<T,bool> visited;
        map<T,int> parent;
        queue<T> q;

        q.push(src);
        visited[src] = true;
        parent[src] = src;

        while(!q.empty()){
            T node = q.front();
            q.pop();
            // Iterate over the neighbors
            for(T neighbor : adjList[node]){
                if(visited[neighbor]==true && parent[node]!=neighbor){
                    return true;
                }else if(!visited[neighbor]){
                    visited[neighbor] = true;
                    parent[neighbor] = node;
                    q.push(neighbor);
                }
                

            }
        }

        return false;
    }

    bool isCyclicHelperDFS(T node, map<T,bool>& visited, T parent){

        visited[node] = true;

        for(T neighbor: adjList[node]){
            
            if(!visited[neighbor]){
                bool cycleDetected = isCyclicHelperDFS(neighbor, visited, node);
                if(cycleDetected){
                    return true;
                }
            }else if(neighbor!=parent){
                return true;
            }

        }

        return false;
    }
    // Check for Undirected graph
    bool isCyclicDFS(){
        map<T, bool> visited;
        
        
        // call for finding cycle
        for(auto i:adjList){
            T node = i.first;
            if(!visited[node]){
                bool ans = isCyclicHelperDFS(node,visited,node);
                if(ans==true){
                    return true;
                }
            }
        }

        return false;

    }

    bool isCyclicHelper(T node, map<T, bool>& visited, map<T, bool>& inStack){

        // Processing the current node - visited and inStack
        visited[node] = true;
        inStack[node] = true;

        // Explore the neighbors of the node
        for(T neighbor: adjList[node]){
            // Two thigs can happen
            // Current node is not visited but it's further branch is leading to a cycle - if case
            // It is visited and is also in stack thus making a cycle - else if case
            if(!visited[neighbor] && isCyclicHelper(neighbor, visited, inStack) || inStack[neighbor]){
                return true;
            }
                
        }
        inStack[node] = false;
        return false;
        

    }

    bool isCyclic(){
        map<T,bool> visited;
        map<T,bool> inStack;
        // To check for cycle in eac dfs tree
        for(auto i:adjList){
            T node = i.first;
            if(!visited[node]){
                bool cyclePresent = isCyclicHelper(node, visited, inStack);
                if(cyclePresent==true){
                    return true;
                }
            }
        }
        // Cycle is not present
        return false;
    }
    

};

int main(){
    Graph <int>g;
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(4,3);
    g.addEdge(2,3);
    
    Graph<int> g2;
    g2.addEdge(0,1,false);
    g2.addEdge(1,3,false);
    g2.addEdge(0,2,false);
    g2.addEdge(2,4,false);
    g2.addEdge(2,5,false);
    g2.addEdge(3,0,false);
    g2.addEdge(4,5,false);

    if(g.isCyclicBFS(1)){
        cout<<"Cyclic Graph (BFS)\n";
    }else{
        cout<<"Acyclic Graph (BFS)\n";
    }

    if(g.isCyclicDFS()){
        cout<<"Cyclic Graph (DFS)\n";
    }else{
        cout<<"Acyclic Graph (DFS)\n";
    }

    if(g2.isCyclic()){
        cout<<"Cyclic Graph (Directed)\n";
    }else{
        cout<<"Acyclic Graph (Directed)\n";
    }



    return 0;

}
