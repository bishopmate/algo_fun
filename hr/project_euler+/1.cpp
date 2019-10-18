#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        uint64_t sum = 0 ;
        set<int> s;
        for(int i = 3;i<n;i+=3){
            s.insert(i);
        }
        for(int i = 5;i<n;i+=5){
            s.insert(i);
        }
        set<int>::iterator it;
        for(it = s.begin();it!=s.end();it++)
            sum += (*it);
        cout<<sum<<"\n";    
    }   
    return 0;
}
