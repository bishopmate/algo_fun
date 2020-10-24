#include<bits/stdc++.h>
using namespace std;
void sieve(int *numbers,int range){
  numbers[1] = 0;
  numbers[0] = 0;
  numbers[2] = 1;
  // Marking all odd numbers as prime(For Initialisation only)
  for(int i =3; i<= range;i+=2)
        numbers[i] = 1;


  for(int i = 3; i<=range;i+=2){// Optimisation 1. We look only for odd numbers and all even numbers are marked non-prime 
                                // in the beginning itself as all the numbers were declared non-prime initially.  
      if(numbers[i]){// i is a prime
          for(int j = i*i;j<=range;j+=2*i){// Optimisation 2. We start the loop for i^2 rather than 2*i
              numbers[j] = 0;              // Optimisation 3. Our loop is incremented with 2*i rather than i because we know 
          }                                //   that initially j is odd and i is also odd and odd+odd = even which would have
      }                                    //   already marked non-prime and is an unnecessary iteration 
                                           //   while odd + ((2*odd)=even) = odd is only required to know all prime numbers
                                           
  }
  // Time Complexity is O(N*log(log(N)))
  //return numbers;
}
int main(){
    int range;
    cin>>range;
    int numbers[range+1] = {0};// Marking all numbers as non prime initially
    
    
    sieve(numbers,range);
    for(int i = 1;i <= range;i++){
        if(numbers[i])
            cout<<i<<" ";
    }
}