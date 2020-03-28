#include<bits/stdc++.h>
using namespace std;
int count(int arr[], int m, int n){
    int i,j,x,y;
    int table[n+1][m];
    
    for(i=0;i<m;++i)
        table[0][i] = 1;
    
    for(i=1;i<=n;++i){
        for(j=0;j<m;++j){
            // Including
            if(i-arr[j]>=0){
                x = table[i-arr[j]][j];
            }else
                x = 0;
            // Excluding
            if(j>=1)
                y = table[i][j-1];
            else
                y=0;
            
            table[i][j] = x+y;
        
        }
    }
     
    
    return table[n][m-1];
    
    
}

int main(){
    
    int arr[] = {1, 2, 3}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    int n = 4; 
    cout << count(arr, m, n); 

}