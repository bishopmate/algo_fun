#include<bits/stdc++.h>
#define int long long
using namespace std;
int solve(int a[], int prefixSum[], int dp[][401], int i, int j){
  if(dp[i][j] != (int)-1)
    return dp[i][j];

  if((j - i) == 1)
    return dp[i][j] = (a[i] + a[j]);
  
  if(j == i)
    return dp[i][j] = (int)0;
  int mnm = INT64_MAX;
  for(int join = i; join < j; join++){

    mnm = min((prefixSum[j] - prefixSum[i-1] + solve(a, prefixSum, dp, i, join) + solve(a, prefixSum, dp, join+1, j)), mnm);
  }
  return dp[i][j] = mnm;
}
signed main(){
  int dp[401][401];
  for(int i=0; i <= (int)400; i++)
    for(int j=0; j <= (int)400; j++)
      dp[i][j] = -1;
  int prefixSum[401];
  prefixSum[0] = (int)0;
  int n;
  cin>>n;
  int a[n+1];
  for(int i=1; i<=n; i++){
    cin>>a[i]; prefixSum[i] = prefixSum[i-1] + a[i];
  }
  int ans = solve(a, prefixSum, dp, (int)1, n);
  cout<<ans<<endl;
  return 0;
}
