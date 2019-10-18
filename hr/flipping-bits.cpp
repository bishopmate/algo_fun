#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    int i=0,arr[32];
    while(n>=1){
        if(n%2==0)
        arr[i++]=1;
        else
        arr[i++]=0;
        n/=2;
    }
    while(i<32){
        arr[i] = 1;i++;
    }
    n=1;
    for(i=31;i>=0;i--){
        cout<<arr[i];n+=(arr[i]*pow(2,i));
    }
    n-=1;
    cout<<"\n"<<n;    
}
