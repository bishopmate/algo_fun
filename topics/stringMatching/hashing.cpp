#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#define ll long long
using namespace std;
ll compute_hash(string& s){
    const int p= 31;
    const int m = 1e9 + 9;
    ll hash_value = 0;
    ll p_pow = 1;
    for(char c:s){
        hash_value = ((hash_value) + (c - 'a' + 1)*p_pow)%m; // note +1 added since a = '1' will be taken and not 'a' = 0
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

vector<vector<int>> group_identical_strings(vector<string>& s){
    int n = s.size();
    vector<pair<ll, int>> hashes(n);
    for(int i=0; i<n; ++i)
        hashes[i] = {compute_hash(s[i]),i};
    
    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    for(int i=0; i<n; ++i){
        if(i==0 || hashes[i].first != hashes[i-1].first) // if it is the first group or if the hash values of adjacent hashes
            groups.emplace_back();                       // differ then we create a new group
        
        groups.back().push_back(hashes[i].second); // if the hashes are equal or if a new group is created then it would have been just 
    }                                              // created at the back of the vector and there we group the indices of the same group together

    return groups;

}

int main(){
    int n;
    cin>>n;
    string current_string;
    vector<string> s;
    for(int i=0; i<n; ++i){
        cin>>current_string;
        s.push_back(current_string);
    }
    vector<vector<int>> groups = group_identical_strings(s);
    int no_of_groups = groups.size();
    for(int i=0; i<no_of_groups; ++i){
        int group_size = groups[i].size();
        for(int j=0; j<group_size; ++j)
            cout<<groups[i][j]<<" ";
        cout<<endl;
    }

}

/*
    Sample Input
7
same
mase
same
name
name
mane
game

*/