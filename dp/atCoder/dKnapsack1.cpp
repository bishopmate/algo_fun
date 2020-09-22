#include<bits/stdc++.h>
#define ll long long
#define PI 3.14159265
using namespace std;
void solve(){
	ll n,w;
	cin>>n>>w;
	ll a[n][2];
	for(ll i=0; i<n; ++i){
		cin>>a[i][0]>>a[i][1];
	}
	cout<<endl;
	ll dp[n+1][w+1];
	
	for(ll i=0; i<=n; i++){
		for(ll j=0; j<=w; ++j){
			if(i==0 || j==0){
				dp[i][j] = 0;
				
			}else if(a[i-1][0] <= j){
				dp[i][j] = max(dp[i-1][j - a[i-1][0]] + a[i-1][1],dp[i-1][j]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout<<dp[n][w]<<"\n";
	
	
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
