#include<bits/stdc++.h>
#define int long long
int mod = 1e9 + 7;
using namespace std;

signed main(){
  int n,k;
  cin>>n>>k;
  vector<int> v(n+1);
  for(int i=1; i <= n; i++)
    cin>>v[i];
  sort(v.begin(), v.end());
  int dp[n+1][k+1];
  for(int j=0; j <= k; j++)
    dp[1][j] = (j > v[1]) ? 0 : 1;

  for(int i=2; i<=n; i++){
    for(int j=0; j<= k; j++){
      if(j == 0)
        dp[i][j] = dp[i-1][j];
      else{
        dp[i][j] = (mod + dp[i][j-1] + dp[i-1][j] - (((j - v[i] - 1) >= 0) ? dp[i-1][j - v[i]-1] : 0))%mod;
      }
    }
  }
  
  cout<<dp[n][k]<<endl;
  return 0;
}
