#include<iostream>
#include<map>
#include<list>
#include<typeinfo>
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

    void print(){

        // Iterate over map
        for(auto i:adjList){
            cout<<i.first<<"->";//<<typeid(i).name()<<" :";
            for(T entry:i.second){
                cout<<entry<<" ";
            }
            cout<<"\n";
        }
    }

     void dfsHelper(T node, map<T,bool> &visited, list<T> &ordering){
        visited[node] = true;
        
        for(T neighbor: adjList[node]){
            if(!visited[neighbor]){
                dfsHelper(neighbor,visited, ordering);
            }
        }

        ordering.push_front(node);
        
    }

    void dfsTopologicalSort(){
        map<T,bool> visited;
        list<T> ordering;
        for(auto i: adjList){
            T node = i.first;
            if(!visited[node])
            dfsHelper(node, visited, ordering);
        }
        // Printing the Topologically Sorted graph
        for(auto i: ordering){
            cout<<"\""<<i<<"\"->";
        }
    }

};

int main(){
    Graph <string>g;
    g.addEdge("Eng","Prog Logic",false);
    g.addEdge("Maths","Prog Logic",false);
    g.addEdge("Prog Logic","HTML",false);
    g.addEdge("Prog Logic","Python",false);
    g.addEdge("Prog Logic","Java",false);
    g.addEdge("Prog Logic","JS",false);
    g.addEdge("Py","Web Dev",false);
    g.addEdge("HTML","CSS",false);
    g.addEdge("CSS","JS",false);
    g.addEdge("JS","Web Dev",false);
    g.addEdge("Java","Web Dev",false);
    // g.addEdge("Py","Web Dev",false);
    g.dfsTopologicalSort();

   

    // Graph <int>g2;
    // g2.addEdge(1,2);
    // g2.addEdge(100,2);
    // g2.addEdge(100,3);
    // g2.print();
    return 0;
    

}
