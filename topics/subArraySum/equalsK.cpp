#include<bits/stdc++.h>
#define ll long long
#define PI 3.14159265
using namespace std;
void sumEqualsK(int arr[], int n, int k){
    unordered_map<int,vector<int>> ma;
    int sum = 0;
    ma.insert({0,{-1}});
    for(int i=0; i<n;++i){
        sum += arr[i];
        ma[sum].push_back(i);
    }
    sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(ma.count(sum-k)>0){
            cout<<"Sum present from index "<<ma[sum-k][0]+1<<" to "<<i<<"\n";
            return;
        }
    }
    cout<<"Sum not present in any subarray\n";
    return;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int arr[] = {10,2,-2,-20,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = -10;
    sumEqualsK(arr,n,sum);
    return 0;
}
