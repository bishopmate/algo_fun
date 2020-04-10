#include<bits/stdc++.h>
#define forn(i,a,b) for(int i=a; i<b; ++i)
using namespace std;

void build(int a[],int tree[], int tl, int tr, int index){

    if(tl==tr){
        tree[index] =a[tl];  
    }else{
        int tm = (tl+tr)/2;
        build(a,tree,tl,tm,2*index);
        build(a,tree,tm+1,tr,2*index+1);
        tree[index] = min(tree[2*index], tree[2*index+1]); 
    }
    return;
}

void update(int tree[], int tl, int tr, int pos,int new_val, int index){
    if(tl==tr){
        tree[index] = new_val;
    }else{
    
        int tm = (tl+tr)/2;
        if(pos<=tm){
            update(tree,tl,tm,pos,new_val,2*index);
        }
        else{
            update(tree,tm+1,tr,pos,new_val,2*index+1);
        }
        tree[index] = min(tree[2*index], tree[2*index+1]);
    }
    return;
}

int query(int tree[], int tl, int tr, int l, int r, int index){
    if(l>r){
        return INT_MAX;
    }
    if(tl==l&&tr==r){
        return tree[index]; 
    }
    int tm = (tl+tr)/2;
    int left = query(tree,tl,tm,l,min(tm,r),2*index);
    int right = query(tree,tm+1,tr,max(l,tm+1),r,2*index+1);
    return min(left,right);

}

int main(){

    int n,q;
    cin>>n>>q;
    int a[n];
    int tree[4*n+1];
    forn(i,0,4*n+1) tree[i] = -1;
    for(int i =0; i<n;++i)
        cin>>a[i];
    build(a,tree,0,n-1,1);
    forn(i,0,4*n+1) cout<<tree[i]<<" ";
    cout<<endl;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            cout<<query(tree,0,n-1,l-1,r-1,1)<<"\n";
        }else{
            int pos,val;
            cin>>pos>>val;
            update(tree,0,n-1,pos-1,val,1);
        }
    }
    
    return 0;

}
