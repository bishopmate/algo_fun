// To find number of primes between large numbers
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void sieve(int *numbers,int range){
  numbers[1] = 0;
  numbers[0] = 0;
  numbers[2] = 1;
  
  for(int i =3; i<= range;i+=2)
        numbers[i] = 1;


  for(int i = 3; i<=range;i+=2){
      if(numbers[i]){
          for(int j = i*i;j<=range;j+=2*i){ 
              numbers[j] = 0;                 
          }                                   
      }                                        
                                              
                                           
  }
  
}
int main(){
    int range = 10000;
    int numbers[range+1] = {0};
    sieve(numbers,range);
    long long int a,b;
    cin>>a>>b;
    bool bignumbers[b-a+1];
    memset(bignumbers,1,sizeof(bignumbers));
    for(ll i = 2; i*i<=b; i++){
        for(ll j = a; j<= b; j++){
                if(numbers[i]){
                    if(j==i)
                        continue;// To check overlapping condition
                    if( j%i == 0)
                        bignumbers[j-a] = 0;
                }
        }
    }
    int res = 1;
    for(ll i =a; i<=b; i++)
        res +=bignumbers[i-a];    
    cout<<"There are "<<res<<" prime numbers in the given range";


}