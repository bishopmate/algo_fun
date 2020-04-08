#include<bits/stdc++.h>
using namespace std;
class DSU{
    map<int, int> parent;
    map<int, int> size;
    map<int, int> rank;
public:
    void make_set(int v){
        parent[v] = v;
    }
    
    int find_set(int a){
        if(parent[a]!=a){
            parent[a] = find_set(parent[a]);    // Path Compression Optimization
            return parent[a];
        }
        return a;
    }
    
    void union_sets(int a, int b){
        
        a = find_set(a);
        b = find_set(b);
        if(a!=b){
            parent[b] = a;
        }
    }

    void make_set_by_size(int v){
        parent[v] = v;
        size[v] = 1;
    }

    void union_sets_by_size(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a!=b){
            if(size[a]<size[b]){
                swap(a,b);
            }
            parent[b] = a;
            size[a] += size[b];

        }
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
    void print_ranks(){
        cout<<"The ranks of elements are\n";
        for(auto x:rank){
            cout<<x.first<<" rank's is "<<rank[x.first]<<"\n";
        }
    }
    void print_sizes(){
        cout<<"The size of elements are\n";
        for(auto x:size){
            cout<<x.first<<" size is "<<size[x.first]<<"\n";
        }
    }




};


 

int main(){
    DSU dsu;
    dsu.make_set_by_rank(1);
    dsu.make_set_by_rank(2);
    dsu.make_set_by_rank(3);dsu.union_sets_by_rank(1,2);dsu.union_sets_by_rank(2,3);

    dsu.make_set_by_rank(4);
    dsu.make_set_by_rank(5);dsu.union_sets_by_rank(4,5);
    // union_sets_by_rank(1,4,parent);
    for(int i=1; i<=5; ++i){
        cout<<i<<" belongs to set "<<dsu.find_set(i)<<"\n";
    }
    dsu.print_ranks();
    DSU dsu2;
    dsu2.make_set_by_size(1);
    dsu2.make_set_by_size(2);
    dsu2.make_set_by_size(3);dsu2.union_sets_by_size(1,2);dsu2.union_sets_by_size(2,3);

    dsu2.make_set_by_size(4);
    dsu2.make_set_by_size(5);dsu2.union_sets_by_size(4,5);
    // union_sets_by_size(1,4,parent);
    for(int i=1; i<=5; ++i){
        cout<<i<<" belongs to set "<<dsu2.find_set(i)<<"\n";
    }
    dsu2.print_sizes();  
}