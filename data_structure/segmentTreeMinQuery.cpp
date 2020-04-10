#include<bits/stdc++.h>
#define forn(i,a,b) for(int i=a; i<b; ++i)
using namespace std;

// Reference for Studying Segment Tree -   https://cp-algorithms.com/data_structures/segment_tree.html
// I cannot share the link to this Problem Statement due to some reasons, So I have tried to picture the Problem Statement here.


/* 

Problem Statement 


You are given an array A of n elements and Q queries. Each query can be of following types:

    1 L R: Print the minimum value in AL, AL+1, AL+2….,AR.
    2 X Y: Update the value of Ax with Y.

Input Format 

First line contains integers N and Q, denoting the number of elements and number of queries.
Next line contains N integers, denoting A1, A2, A3….,AN. Next Q lines contains Q queries.

Constraints

1<=N,Q<=10^5 |Ai|,|Y|<=10^9 1<=L,R,X<=N

Sample Input

5 5
1 4 3 5 2
1 1 5
2 3 9
1 2 4
1 2 5
1 3 4

Corresponding Output

1
4
2
5

*/
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
