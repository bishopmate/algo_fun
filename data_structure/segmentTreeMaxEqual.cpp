#include<bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> v1, vector<int> v2){

    vector<int> result;
    while(!v1.empty()&&!v2.empty()){
        if(v1.front()>v2.front()){
            result.push_back(v2.front());
            v2.erase(v2.begin());
        }else{
            result.push_back(v1.front());
            v1.erase(v1.begin());
        }
    }
    while(!v1.empty()){
        result.push_back(v1.front());
        v1.erase(v1.begin());
    }
    while(!v2.empty()){
        result.push_back(v2.front());
        v2.erase(v2.begin());
    }

    return result;

}
void build(int a[], vector<vector<int>>& tree, int tl, int tr, int index){
    if(tl==tr){
        vector<int> v;v.push_back(a[tl]);
        tree[index] = v;
    }else{
        int tm = (tl+tr)/2;
        build(a,tree,tl,tm,2*index);
        build(a,tree,tm+1,tr,2*index+1);
        tree[index] = merge(tree[2*index],tree[2*index+1]);
    }
    return;
}
int less_eq_k(vector<int>& a, int k){
    int s=0,e=a.size()-1,res;
    int n=e,mid;
    while(s<=e){
        mid = (s+e)/2;
        if(a[mid]>=k&&mid==s){
            return n-s+1;
        }
        if(a[mid]>=k){
            if(a[mid-1]<k){
                return (n-mid+1);
            }else{
                e=mid-1;
            }
        }else{
            s = mid+1;
        }
    }
    return 0;
}
int query(vector<vector<int>>& tree, int tl, int tr, int l, int r,int k, int index){
    if(l>r){
        return 0;
    }
    if(tl==l&&tr==r){
        return less_eq_k(tree[index],k);
    }
    int tm = (tl+tr)/2;
    int left = query(tree,tl,tm,l,min(r,tm),k,2*index);
    int right = query(tree,tm+1,tr,max(l,tm+1),r,k,2*index+1);
    return (left+right);

}
int main(){
    int n;
    cin>>n;
    int a[n];
    vector<vector<int>> tree(4*n+1);
    for(int i=0;i<n;++i) cin>>a[i];
    build(a,tree,0,n-1,1);
    int q;
    cin>>q;
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        cout<<query(tree,0,n-1,l-1,r-1,k,1)<<"\n";

    }
}
