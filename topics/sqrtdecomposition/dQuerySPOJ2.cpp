#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Q = 2e5+5;

int compressedValue = 0;
struct query{
  int l,r,idx,lb,ans;
};
bool comparator(query& a, query& b){
  return (a.lb < b.lb) || (a.lb == b.lb && a.r < b.r);
}
signed main(){
  int n;
  cin>>n;
  int arr[n], freq[n], rev[n];
  map<int, int> ma;
  for(int i=0; i<n; i++){
    cin>>arr[i];
    ma[arr[i]]; // Making entry in map, to be used in Coordinate Compression
  }

  // Coordinate Compression
  for(auto &it:ma){
    it.second = ++compressedValue;
    rev[compressedValue] = it.first;
  }

  for(int i=0; i<n; i++){
    arr[i] = ma[arr[i]];
  }
  // Coordinate Compression Done
  
  memset(freq, 0, sizeof(freq));
  int blocksize = max(1LL, (int)sqrt(n));
  int q;
  cin>>q;
  query queries[q];
  for(int i=0; i<q; i++){
    int l,r;  cin>>l>>r;
    l--, r--;
    queries[i].l = l, queries[i].r = r, queries[i].idx = i, queries[i].lb = l/blocksize;
  }
  sort(queries, queries+q, comparator);
  freq[arr[0]]++;
  int left=0, right=0;
  int ans = 1;
  int result[q];
  for(int i=0; i<q; i++){
    if(right < queries[i].r){
      while(right < queries[i].r){
        right++;
        freq[arr[right]]++;
        
        if(freq[arr[right]] == 1LL){
          ans++;
        }

      }
    }else if(right > queries[i].r){
      while(right > queries[i].r){
        freq[arr[right]]--;
        if(freq[arr[right]] == 0LL){
          ans--;
        }
        right--;
      }
    }

    if(left < queries[i].l){
      while(left < queries[i].l){
        freq[arr[left]]--;
        if(freq[arr[left]] == 0LL){
          ans--;
        }
        left++;
      }
    }else if(left > queries[i].l){
      while(left > queries[i].l){
        left--;
        freq[arr[left]]++;
        if(freq[arr[left]] == 1LL){
          ans++;
        }
      }
    }
    result[queries[i].idx] = ans;
  }cout<<endl;
  for(int i=0; i<q; i++){
    cout<<result[i]<<"\n";
  }
  return 0;
}
