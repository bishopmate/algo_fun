/*
    Problem Statement
    Find the first element greater than or equal to X in a sorted array;

*/
int lowerBound(int nums[], int n, int target){
    int left = 0, right = n-1, mid, ans = -1;
    while(left<=right){
        mid = left + (right - left)/2;
        if(nums[mid] >= target){
            ans = mid;
            right = mid - 1; // If we have found an element that satisfies our condition another better answer will
        }else{               // always be definitely on the left side if it exists
            left = mid + 1;
        }
    }

    return ans; // -1 is returned if all the elements are less than target
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums;
    int arr[] = {1,2,4,6,8,10,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 5;
    cout<<"The first element less than or equal to "<<target<<" is "<<lowerBound(arr, n, target)<<"\n";
    return 0;
}
