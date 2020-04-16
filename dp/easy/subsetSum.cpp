/*
    Problem Statement -
    Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool isSubsetSum(int sum, int arr[], int n){
    
    // Here the row indicates the sum and the columns indicate the value in the array given to us
    bool dp[sum+1][n+1];
    memset(dp,false,sizeof(dp));
    // Sum = 0 everytime possible
    for(int i=0;i<n;++i)
        dp[0][i] = true;
    // Without any value any sum >= 1 is not possible
    for(int i=1;i<=sum;++i)
        dp[i][0] = false;
    
    for(int i=1; i<=sum; ++i){

        for(int j=1;j<=n; ++j){
            if(i<arr[j-1])
                dp[i][j] = dp[i][j-1];  // Just give the answer for the current sum without including the value at '(j-1)th' position
            else
                dp[i][j] = dp[i-arr[j-1]][j-1] || dp[i][j-1]; // If it is possible to give the sum with or without including the element 
        }                                                     // at '(j-1)th' position

    }

    return dp[sum][n];
}

int main(){
    int set[] = {3, 34, 4, 12, 5, 2}; 
    int sum = 36; 
    int n = sizeof(set)/sizeof(set[0]); 
    if (isSubsetSum(sum, set, n) == true) 
        printf("Found a subset with given sum"); 
    else
        printf("No subset with given sum"); 

    return 0;
}
