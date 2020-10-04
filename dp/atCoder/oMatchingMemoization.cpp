#include<bits/stdc++.h>
#define int long long
int mod = 1e9+7;
using namespace std;
int solve(int compatabilityMatrix [][21],vector<vector<int>>& dp, int mask, int i, int n){
  if(i == n)
    return 1;
  if(dp[i][mask] != -1)
    return dp[i][mask];

  int ways = 0;
  for(int j=0; j<n; j++){
    if(compatabilityMatrix[i][j]==1 && ((mask>>j)&1) == 1){
      ways = (ways + solve(compatabilityMatrix, dp, (mask - (1<<j)), i+1, n) )%mod;
    }
  }

  return dp[i][mask] = ways;
}
signed main(){
  int n;
  cin>>n;
  int compatibilityMatrix[21][21];
  vector<vector<int>> dp(n, vector<int>((1<<21), -1));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>compatibilityMatrix[i][j];
    }
  }
  int ans = solve(compatibilityMatrix, dp, ((1<<n)-1), 0, n);
  cout<<ans<<endl;
  return 0;
}
