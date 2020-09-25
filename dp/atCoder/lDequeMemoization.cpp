#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[3000][3000][2];
int func(int i, int j, int arr[], bool taro = true){
  int idx = taro ? 0 : 1;
  if(dp[i][j][idx] != INT64_MAX)
    return  dp[i][j][idx];
  if(i == j){
    if(taro){
      return dp[i][j][idx] = arr[i];
    }else{
      return dp[i][j][idx] = arr[i]*(-1);
    }
  }else if(taro){
    taro = !taro;
    return dp[i][j][idx] = max(arr[i] + func(i+1, j, arr, taro),arr[j] + func(i, j-1, arr, taro));
  }else{
    taro = !taro;
    return dp[i][j][idx] = min(func(i+1, j, arr, taro) - arr[i], func(i, j-1, arr, taro) - arr[j]);
  }
}

signed main(){
  int n;  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++)
    cin>>arr[i];
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      dp[i][j][0] = dp[i][j][1] = INT64_MAX;
    }
  }
  int ans = func(0, n-1, arr);
  cout<<ans<<endl;
  return 0;
}
