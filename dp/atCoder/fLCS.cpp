#include<bits/stdc++.h>
using namespace std;

int lcsMemo(int i, int j, string &s, string &t, vector<vector<int>>& dp){
    if(i >= (int)s.size() || j >= (int)t.size() || i<0 || j<0)
        return 0;
    if(dp[i][j] != -1){
        return dp[i][j];
    }else if(s[i] == t[j]){
        dp[i][j] = 1 + lcsMemo(i+1, j+1, s, t, dp);
        return dp[i][j];
    }else{
        int firstRemoval = lcsMemo(i+1, j, s, t, dp);
        int secondRemoval = lcsMemo(i, j+1, s, t, dp);
        dp[i][j] = max(firstRemoval, secondRemoval);
        return dp[i][j];
    }

}
string lcsWord(vector<vector<int>>& dp, string s, string t){
    int i = 0, j = 0;
    string res = "";
    while(i<dp.size() && j<dp[0].size()){
        if(s[i] == t[j]){
            res += s[i];
            i++; j++;
        }else if(i+1 == dp.size()){
            j++;
        }else if(j+1 == dp[0].size()){
            i++;
        }else if(dp[i+1][j] > dp[i][j+1]){
            i++;
        }else{
            j++;
        }

    }
    return res;
}
int main(){
    string s,t;
    cin>>s>>t;
    vector<vector<int>> dp((int)s.size(), vector<int>((int)t.size(), -1));
    int lcsLength = lcsMemo(0,0,s,t,dp);
    string answer = lcsWord(dp, s, t);
    cout<<answer<<endl;
    return 0;
}
