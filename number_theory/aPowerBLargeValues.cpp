#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 1000000007;
ll stringToInt(string a,ll m){
    ll ans = 0;
    for(int i = 0;i<a.size();++i){
        ans = (ans*10)%m + a[i] - '0';
        ans = ans%m;
    }
    return ans;

}
ll Power(ll a, ll b, ll m){

    ll res = 1;
    while(b>0){
        if(b&1){
            res = ((res%m)*(a%m))%m;
        }
        a = ((a%m)*(a%m))%m;
        b = b>>1;
    }
    return res;

}
int main(){
    string a,b;
    cin>>a>>b;
    ll x,y;
    x = stringToInt(a,mod);
    y = stringToInt(b,mod-1);
    ll answer = Power(x,y,mod);
    cout<<answer;
}
// Sample Input - 
// 3
// 100000000000000000000000000
// Output
// 835987331