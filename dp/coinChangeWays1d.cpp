#include<bits/stdc++.h>
using namespace std;
int count(int arr[], int m, int n){
    int i,j,x,y;
    int table[n+1];
    
    memset(table,0,sizeof(table));
    
    table[0] = 1;
    
    for(i=0;i<m;++i){
        for(j = arr[i];j<=n;++j){
            table[j] += table[j-arr[i]];
        }
    }
    
    return table[n];
    
    
}

int main(){
    
    int arr[] = {1, 2, 3}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    int n = 4; 
    cout << count(arr, m, n); 

}