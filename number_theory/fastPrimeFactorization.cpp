#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> fastPrimeFactorization(int limit){
  vector<vector<int>> helper;
  int sieve[limit+1];
  memset(sieve, 0, sizeof(sieve));
  sieve[1] = 1;
  for(int i=2; i <= limit; i++){
    if(!(sieve[i])){
      sieve[i] = i;
      for(int j=i*i; j <= limit; j+=i){
        sieve[j] = i;
      }
    }
  }
  helper.push_back({0});
  helper.push_back({1});
  for(int i=2; i <= limit; i++){
    vector<int> v;
    int cur = i;
    while(cur > 1){
      v.push_back(sieve[cur]);
      cur = cur/sieve[cur];
    }
    helper.push_back(v);
  }
  return helper;

}


int main(){
  int n;
  cin>>n;
  vector<vector<int>> ans = fastPrimeFactorization(n);;
  for(int i=0; i<ans.size(); i++){
    cout<<i<<" - ";
    int j=0, m = ans[i].size();
    for(auto x:ans[i]){
      cout<<x;
      if(j++ < m-1)
        cout<<"*";
    }
    cout<<endl;
  }
  return 0;
}