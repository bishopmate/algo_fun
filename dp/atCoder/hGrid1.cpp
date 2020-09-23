#include<bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int memoGrid(vector<vector<char>>& mat, vector<vector<int>>& dp, int i, int j, int h, int w){
    if(i >= h || j>= w)
        return 0;
    if(mat[i][j] == '#')
        return 0;
    if(i==(h-1) && j==(w-1))
        return 1;
    
    if(dp[i][j] != -1)
        return dp[i][j];

    int count = (memoGrid(mat, dp, i+1, j, h, w)%mod + memoGrid(mat, dp, i, j+1, h, w)%mod)%mod;
    return dp[i][j] = count;
       
}
int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> mat(h, vector<char>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>> dp(h, vector<int>(w, -1));
    int ans = memoGrid(mat, dp, 0, 0, h, w);
    cout<<ans;
    return 0;
}
