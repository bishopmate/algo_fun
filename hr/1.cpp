#include<bits/stdc++.h>
using namespace std;
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {


    int n1 = scores.size(),n2=alice.size();
    set<int> scores1;
    for(int i=0;i<n1;i++){
        scores1.insert(scores[i]);
    }   
    int fn = scores1.size();
    int a[fn];
    set<int,greater<int>>::iterator itr;
    int i =0 ;
    cout<<"Inserted elements are";
    for(itr = scores1.begin();itr!=scores1.end();itr++){
        a[i] = *itr;//cout<<a[i]<<" ";
        i++;
    }
    cout<<endl;
    i=0;
    sort(a,a+fn,greater<int>());
    for(i=0;i<fn;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    i=0;
    vector<int> result;
    for(i=0;i<n2;i++){
        int x = alice[i];int f = 0;
        for(int j = 0;j<fn;j++){
            if(a[j]<x){
                 result.push_back(j+1);f=1;
                 break;
            }else if(a[j]==x){
                result.push_back(j);f=1;
                 break;
            }
        }

        if(f==0)
            result.push_back(fn+1);
    }
    cout<<"The result is ";
    vector<int> :: iterator vec;
    for(vec = result.begin();vec!=result.end();vec++){
        cout<<*vec<<" ";
    }
    cout<<endl;
    return result;


}
using namespace std;
int main(){
    vector<int> scores,alice;
    vector<int>:: iterator it;
    int x,y,z;
    cin>>x;
    for(int i=0;i<x;i++){
        cin>>z;
        scores.push_back(z);
    }
    for(it = scores.begin();it!= scores.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    cin>>y;
    for(int i=0;i<y;i++){
        cin>>z;
        alice.push_back(z);
    }
    for(it = alice.begin();it!= alice.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    vector<int> result = climbingLeaderboard(scores,alice);
    
    for(it = result.begin();it!= result.end();it++){
        cout<<*it<<" ";
    }


}