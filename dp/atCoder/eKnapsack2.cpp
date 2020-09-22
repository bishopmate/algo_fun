#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define PI 3.14159265
const ll INF = 1e18L + 5;
void min_self(ll &a, ll &b){
	a = min(a,b);
}
void solve(){
	ll n,w;
	scanf("%lld%lld", &n, &w);
	vector<ll> weight(n+1), value(n+1);
	for(int i=0; i<n; ++i){
		scanf("%lld%lld", &weight[i], &value[i]);
	}
	int sum_value = 0;
	for(auto x:value){
		sum_value += x;

	}
	
	// dp[i] - the minimum total weight with total value exactly i

	vector<ll> dp(sum_value+1, INF);
	dp[0] = 0;
	for(int item = 0; item < n; ++item){
		for(int value_already = sum_value - value[item]; value_already>=0; --value_already){
			dp[value_already+value[item]] = min(dp[value_already+value[item]], dp[value_already] + weight[item]);
		}
	}
	
	ll answer = 0;
	for(int i=0; i<= sum_value; ++i){
		if(dp[i] <= w){
			answer = max(answer, (ll) i);
		}
	}	
	printf("%lld\n", answer);
	
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}














