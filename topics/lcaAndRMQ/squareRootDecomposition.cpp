#include<bits/stdc++.h>
using namespace std;
float squareRoot(int number, int precision) 
{ 
	int start = 0, end = number; 
	int mid; 
	float ans;  
	while (start <= end) { 
		mid = (start + end) / 2; 
		if (mid * mid == number) { 
			ans = mid; 
			break; 
		} 

	    if (mid * mid < number) { 
			start = mid + 1; 
			ans = mid; 
		}else{ 
			end = mid - 1; 
		} 
	} 
	float increment = 0.1; 
	for (int i = 0; i < precision; i++) { 
		while (ans * ans <= number) { 
			ans += increment; 
		} 
 
		ans = ans - increment; 
		increment = increment / 10; 
	} 
	return ans; 
} 

void minimumRangeQuery(int arr[], int n){
    int ceilRootSize = ceil(squareRoot(n,2));
    int rangeSolution[ceilRootSize];
    int rootSize = sqrt(n);
    for(int i=0;i<ceilRootSize;++i){
        int j = i*ceilRootSize, limit = (i*(ceilRootSize))+ceilRootSize;
        // cout<<j<<" "<<limit<<"\n";
        int mnm = INT_MAX;
        while(j<n && j<limit){
            mnm = min(mnm, arr[j]);
            j++;
        }
        rangeSolution[i] = mnm;
    }
    for(auto x:rangeSolution)
        cout<<x<<" ";
    cout<<endl;
    int l,r;
    cin>>l>>r;
    l = sqrt(l);
    r = sqrt(r);
     

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    minimumRangeQuery(arr,n);
    return 0;
}