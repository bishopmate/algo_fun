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

string tabulationDP(string s){
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
  // return dp[n-1][n-1];
  vector<char> helper;
  int j = n-1, i = n-1;
  while(j >= 0){
    if(i == 0){
      if(dp[i][j] > dp[i][j-1]){
        helper.push_back(s[j]);
      }
    }else{
      if(dp[i][j] > dp[i-1][j-1]){
        helper.push_back(s[j]);
        i--;
      }
      j--;
    }
  }
  int lrsLength = dp[n-1][n-1];
  string lrs;
  lrs.resize(lrsLength,'x');
  for(int i=0, j=lrsLength-1; i<lrsLength; i++, j--){
    lrs[i] = helper[j];
  }
  return lrs;
}

int main(){

  string s = "aabcbdcbsbddee";
  int n = s.size();
  if(n < 2){
    cout<<"Chotta String kaa kuch nahi ho sakta\n";
  }else{
    int lrsLength = rec(s,0,1,n);
    cout<<"The length of LRS is "<<lrsLength<<" by recursion"<<endl;
    string lrs = tabulationDP(s);
    int lrsLength2 = lrs.size();
    cout<<"LRS retrieved by Tabulation Method is \""<<lrs<<"\" and it's length is also "<<lrsLength2<<" "<<endl;
  }
  return 0;

}
