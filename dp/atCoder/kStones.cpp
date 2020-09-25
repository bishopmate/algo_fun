#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> v(n);
  for(int i=0; i<n; i++)
    cin>>v[i];
  int dp[k+1];
  for(int i=0; i<=k; i++)
    dp[i] = false;
  for(int i=0; i<= k; i++){
    for(int j=0; j<n; j++){
      if(i - v[j] < 0){
        continue;
      }
      if(dp[i - v[j]] == false){
        dp[i] = true;
      }
    }
  }
  if(dp[k]){
    cout<<"First\n";
  }else{
    cout<<"Second\n";
  }
  return 0;
}
