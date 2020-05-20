#include<bits/stdc++.h>
#define ll long long
#define PI 3.14159265
using namespace std;
void sumEqualsK(int arr[], int n, int sum){
    int start = 0;
    int currSum = arr[0];
    int i;
    for(i=1; i<=n; ++i){
        while(currSum>sum && start<i){
            currSum -= arr[start++];
        }
        if(currSum==sum){
            cout<<"Index from "<<start<<" to "<<i-1;
            return;
        }
        if(i<n)
            currSum += arr[i];
    }
    if(currSum==sum){
            cout<<"Index from "<<start<<" to "<<i-1;
            return;
    }
    cout<<"No subarray equals "<<sum<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int arr[] = {100,1,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 100;
    sumEqualsK(arr,n,sum);
    return 0;
}