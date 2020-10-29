#include<bits/stdc++.h>
using namespace std;
int rec(string s,int i, int j, int n){

  if(j>=n || i>=n)
    return 0;

  int mxm = 0;
  for(int x = j; x < n; x++){
  
    if(s[i] == s[x]){
      mxm = max(mxm, 1 + rec(s, i+1, x+1, n));
    }else if(i+1 < x){
      mxm = max(mxm, rec(s, i+1, x, n));
    }

  }
  return mxm;
}

int tabulationDP(string s){
  int n = s.size();
  vector<vector<int>> dp(n, vector<int>(n, 0));

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(s[i] == s[j] && i!=j){
        dp[i][j] = max({(i-1 >= 0 && j-1 >=0) ? dp[i-1][j-1] + 1 : 1, (i-1) >= 0 ? dp[i-1][j] : 0, ((j-1) >= 0 ? dp[i][j-1] : 0)});
      }else{
        dp[i][j] = max( ((i-1) >= 0 ? dp[i-1][j] : 0), ((j-1) >= 0 ? dp[i][j-1] : 0));
      }
    }
  }
  return dp[n-1][n-1];
}

int main(){

  string s = "aabcbdcbsbddee";
  int n = s.size();
  if(n < 2){
    cout<<"Chotta String kaa kuch nahi ho sakta\n";
  }else{
    int lisLength = rec(s,0,1,n);
    cout<<lisLength<<endl;
    int lisTabLength = tabulationDP(s);
    cout<<lisTabLength<<endl;
  }
  return 0;

}
