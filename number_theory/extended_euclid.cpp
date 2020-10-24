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
int x,y,GCD;
void extendedEuclidMethod(int a,int b){
    // Base Case
    if(b==0){
        GCD = a;
        x = 1;
        y = 0;
        return;
    }
    // Recursive case
    extendedEuclidMethod(b,a%b);
    int cX = y;
    int cY = x - (a/b)*y;
    x = cX;
    y = cY;
    return;


}

int main(){
    extendedEuclidMethod(18,30);
    cout<<x<<" "<<y<<"\n";

}