#include<bits/stdc++.h>
using namespace std;
double dp[3001][3001];
double solve(vector<double>& v, double dp[][3001], int n, int x){
    if(x==0)
        return 1;
    if(n==0)
        return 0;
    if(dp[n][x] > -1){
        return dp[n][x];
    }
    dp[n][x] = v[n]*solve(v, dp, n-1, x-1) + (1 - v[n])*solve(v, dp, n-1, x);

    return dp[n][x];
}
int main(){
    cout<<fixed<<setprecision(13);
    int n;
    cin>>n;
    vector<double> v(n+1);
    for(int i=1; i<=n; i++)
        cin>>v[i];
    memset(dp, -1, sizeof(dp));
    double ans = solve(v, dp, n, (n/2)+1);
   
    
    cout<<ans<<endl;
    
    return 0;

}
