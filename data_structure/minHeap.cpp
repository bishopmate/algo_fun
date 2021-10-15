#include <bits/stdc++.h>
using namespace std;
// if 0 indexed then parent is (i-1)/2 else i/2
void bubbleUp(vector<int>& a, int idx){
    if(idx == 0)
        return;
    if(a[idx] < a[(idx-1)/2]){
        swap(a[idx], a[(idx-1)/2]);
        bubbleUp(a, (idx-1)/2);
    }
}
// if 0 indexed then left child is 2*idx+1 else 2*idx
// if 0 indexed then right child is 2*idx+2 else 2*idx+1
void bubbleDown(vector<int>& a, int idx, int& last){
    int left = INT32_MAX, right = INT32_MAX;
    if(2*idx+1 < last){
        left = a[2*idx+1];
    }
    if(2*idx+2 < last){
        right = a[2*idx+2];
    }
    if(left <= right && left <= a[idx]){
        swap(a[2*idx+1], a[idx]);
        bubbleDown(a, 2*idx+1, last); 
    }else if(right <= a[idx] && right <= left){
        swap(a[2*idx+2], a[idx]);
        bubbleDown(a, 2*idx+2, last);
    }
}

int main(){
    char c;
    vector<int> a(1,-1);
    int last = 0;
    cout<<"Press 1 to insert an element\n";
    cout<<"Press 2 to delete an element\n";
    cout<<"Press 3 to print the minimum element\n";

    while(true){
        cin>>c;
        switch(c){
            case '1' : {// insert
                if(a[last] != -1){
                    a.resize(2*(last+1), -1);// Increasing the size
                }
                int val;
                cin>>val;
                a[last] = val;
                bubbleUp(a,last);
                last++;
                cout<<a[0]<<" is now the minimum element\n";
                cout<<"The heap is [";
                for(int i=0; i<last;i++){
                    cout<<a[i];
                    if(i!=last-1)
                       cout<<",";
                }
                cout<<"]\n";
                break;
            }
            case '2' : {// delete
                if(last==0) {
                    cout<<"The heap is empty\n";
                    break;
                }
                a[0] = a[last-1];
                a[last-1] = -1;
                last--;
                bubbleDown(a, 0, last);
                if(last==0){
                    cout<<"The heap is empty\n";break;
                }
                if(a[last/2] == -1){
                    a.resize(last/2+1);
                }
                cout<<a[0]<<" is now the minimum element\n";
                cout<<"The heap is [";
                for(int i=0; i<last;i++){
                    cout<<a[i];
                    if(i!=last-1)
                       cout<<",";
                }
                cout<<"]\n";
                break;
            }
            case '3' : {// getMin
                if(last == 0){
                    cout<<"The heap is empty\n";break;
                }
                cout<<a[0]<<" is the minimum element\n";
                break;
            }
            default:
                break;
        }
    }
    return 0;
}
