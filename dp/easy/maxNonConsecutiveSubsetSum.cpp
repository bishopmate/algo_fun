#include<stdio.h>
#include<iostream>
#include<vector>
/*
  Given an array of N elements a[1], a[2], ... , a[N] find the subset with the maximum
  sum such that the elements of the subset are not consecutive elements.

*/

using namespace std;
int main(){
  int arr[] = {2, 3, 9, 1, 5, 14, 6};
  int n  = sizeof(arr)/sizeof(arr[0]);
  if(n == 1){
    cout<<arr[0];
    return 0;
  }
  int dp[n+1];
  dp[0] = 0;
  dp[1] = arr[0];
  dp[2] = arr[1];
  pair<int, int> ans;
  if(dp[1] > dp[2]){
    ans.first = dp[1];
    ans.second = 1;
  }else{
    ans.first = dp[2];
    ans.second = 2;
  }
  for(int i=2; i<n; i++){
    dp[i+1] = arr[i];
    for(int j=0; j<i; j++){
      dp[i+1] = max(dp[i+1], dp[j] + arr[i]);
    }
    if(ans.first < dp[i+1]){
      ans.first = dp[i+1];
      ans.second = i+1;
    }
  }
  int i = ans.second;
  vector<int> subset;
  subset.push_back(arr[i-1]);
  int nxt = ans.first - arr[i-1];
  i--;
  while(i > 0){
    if(dp[i] == nxt){
      subset.push_back(arr[i-1]);
      nxt = nxt - arr[i-1];
    }
    i--;
  }
  for(i = subset.size()-1; i >= 0; i--){
    cout<<subset[i]<<" ";
  }
  return 0;
}
