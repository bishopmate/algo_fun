/*
Given a floor of size n x m and tiles of size 1 x m. 
The problem is to count the number of ways to tile the given floor using 1 x m tiles. 
A tile can either be placed horizontally or vertically.
Both n and m are positive integers and 2 < = m.
*/


#include<bits/stdc++.h>
using namespace std;
int no_of_ways(int n, int m){
    
    int count [n+1];
    count[0] = 0;
    for(int i=1;i<=n;++i){
        // Recurrence relation
        if(i>m)
            count[i] = count[i-1] + count[i-m];// Either we can place a tile horizontally or vertically
        else if(i==m) // Base case when either all tiles are placed horizontally or vertically
            count[i] = 2;
        else         // Base case when all the tiles can only be placed vertically
            count[i] = 1;
    
    }
    
    return count[n];
}
int main(){
    
    int n = 8,m = 4;
    cout<<no_of_ways(n,m);

}
