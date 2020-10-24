#include<iostream>
using namespace std;
int gcd(int a,int b){
    // base case
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int lcm(int a, int b){
    
    return a*b/(gcd(a,b));
}    

int main(){

    int a;
    cin>>a;
    int b;
    cin>>b;
    cout<<"GCD - "<<gcd(a,b)<<" LCM - "<<lcm(a,b);

}