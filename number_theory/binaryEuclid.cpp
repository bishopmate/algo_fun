#include<bits/stdc++.h>
using namespace std;
int gcdBinary(int a, int b, int res){
  if(a == b){
    return a * res;
  }
  if(a == 0){
    return b*res;
  }else if(b == 0){
    return a*res;
  }
  if(!(a&1) && !(b&1)){
    return gcdBinary((a >> 1), (b >> 1), res*2);
  }else if(!(a&1)){
    return gcdBinary((a >> 1), b, res);
  }else if(!(b&1)){
    return gcdBinary(a, (b >> 1), res);
  }else if(a > b){
    return gcdBinary(a-b, b, res);
  }else{
    return gcdBinary(a, b-a, res);
  }
}
int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main(){
  int a = 1, b = 22;
  cout<<gcd(a,b)<<endl;
  cout<<gcdBinary(a,b,1)<<endl;
  return 0;
}