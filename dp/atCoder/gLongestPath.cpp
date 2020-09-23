#include<bits/stdc++.h>
using namespace std;
int recursiveLongestPath(map<int, vector<int>>& ma, int s){
    if(ma[s].size() == 0)
        return 0;
    int mxm = 0;
    for(auto x:ma[s]){
        int cur = 1 + recursiveLongestPath(ma, x);
        mxm = max(mxm, cur);
    }
    return mxm;
}

int memoLongestPath(vector<vector<int>>& v, int s, vector<int>& dp){
    if(dp[s] != -1)
        return dp[s];

    if(v[s].size() == 0){
        dp[s] = 0;
        return dp[s];
    }
    int mxm = 0;
    for(auto x:v[s]){
        int cur = 1 + memoLongestPath(v, x, dp);
        mxm = max(mxm, cur);
    }

    return dp[s] = mxm;

}
int main(){
    
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n+1);
    int x,y;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        v[x].push_back(y);
    }
    int mxm = 0;
    
    vector<int> dp(n+1, -1);
    for(int i=1; i<=n; i++){
        mxm = max(mxm, memoLongestPath(v, i, dp));
    }
    cout<<mxm<<endl;
    return 0;
}
