#include<bits/stdc++.h>
using namespace std;
int editDist(string& s, string& t, int i, int j, int n, int m, int dp[][1005]){

    if(dp[i][j] != -1)
        return dp[i][j];
    

    if(i==n){ 
        return dp[i][j] = m-j;
    }

    if(j==m){
        return dp[i][j] = n-i;
    }

    if(s[i] == t[j]){
        return dp[i][j] = editDist(s, t, i+1, j+1, n, m, dp);
    }

    int mnm = INT_MAX;

    mnm  = 1 + min(min(editDist(s, t, i, j+1, n, m, dp), editDist(s, t, i+1, j, n, m, dp)), 
            editDist(s, t, i+1, j+1, n, m, dp));

    return dp[i][j] = mnm;

}

int editDistTabulation(string s, string t, int n, int m){
    
    int dp[n+1][m+1];
    
    for(int i=n; i>=0; i--){
        for(int j=m; j>=0; j--){
            if(i==n){
                dp[i][j] = m - j;
            }else if(j==m){
                dp[i][j] = n - i;
            }else if(s[i]==t[j]){
                dp[i][j] = dp[i+1][j+1];
            }else{
                dp[i][j] = 1 + min(min(dp[i+1][j], dp[i][j+1]), dp[i+1][j+1]);
            }
        }
    }
    int i = 0, j = 0, k = 1;
    while(i < n && j < m){
        if(s[i] == t[j]){
            i++; j++;
        }else if(dp[i+1][j+1] <= dp[i][j+1] && dp[i+1][j+1] <= dp[i+1][j]){
            cout<<k<<") change "<<t[j]<<" to "<<s[i]<<endl;i++;j++;k++;
        }else if(dp[i+1][j] <= dp[i+1][j+1] && dp[i+1][j] <= dp[i][j+1]){
            cout<<k<<") add "<<s[i]<<" at "<<i<<" position"<<endl;i++;k++;
        }else{
            cout<<k<<") remove "<<t[j]<<" at "<<j<<" position"<<endl;j++;k++;
        }
    }
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[0][0];
}
int editDistTabulationOneD(string s, string t, int n, int m){
    int dp[2][n+1];
    for(int i=n; i>=0; i--){
        for(int j=m; j>=0; j--){
            if(i==n){
                dp[i%2][j] = m-j;
            }else if(j==m){
                dp[i%2][j] = n-i;
            }else if(s[i] == t[j]){
                dp[i%2][j] = dp[(i+1)%2][(j+1)];
            }else{
                dp[i%2][j] = 1 + min(min(dp[(i+1)%2][j], dp[i%2][(j+1)]), dp[(i+1)%2][(j+1)]);
            }
            // cout<<dp[i%2][j]<<" ";
        }
        // cout<<endl;
    }
    return dp[0][0];
}
int main(){
    string str1 = "sunday"; 
    string str2 = "saturday"; 
    int n = str1.length(), m = str2.length();
    int dp[1005][1005];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m ; j++)
            dp[i][j] = -1;
    }

    // cout<<editDist(str1, str2, 0, 0, n, m, dp)<<endl;
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m ; j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    int changes = editDistTabulation(str1, str2, n, m);
    cout<<"In all "<<changes<<" changes are required to change "<<str2<<" to "<<str1<<endl;
    // cout<<editDistTabulationOneD(str1, str2, n, m)<<endl;
    
    return 0;
}
