#include<bits/stdc++.h>
using namespace std;

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
uint64_t queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {

    int board[n][n];
    //memset(board,0,sizeof(board[0][0]*n*n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           board[i][j]=0;
        }
        //cout<<endl;
    }
    int x,y;
    x = n-r_q,y= c_q-1;
    r_q = x,c_q = y;
    board[x][y] = 2;
    for(int i = 0;i<k;i++){
        x = n-obstacles[i][0],y = obstacles[i][1]-1 ;
        board[x][y] = 1;
    }
    uint64_t count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    //down
    
    for(int i = r_q+1;i<n;i++){
        if(board[i][c_q]){
                break;
        }
        board[i][c_q]=3;
        count++;
    }
    //up
    for(int i = r_q -1;i>=0;i--){
        if(board[i][c_q]){
            break;
        }
        count++;
        board[i][c_q]=3;
    }
    //left
    for(int i=c_q-1;i>=0;i--){
        if(board[r_q][i]){
            break;
        }
        board[r_q][i]=3;
        count++;
    }
    //right 
    for(int i=c_q+1;i<n;i++){
        if(board[r_q][i]){
            break;
        }
        board[r_q][i]=3;
        count++;

    }
    //up-left
    for(int i=r_q-1,j=c_q-1;i>=0,j>=0;i--,j--){
        if(board[i][j]){
            break;
        }
        board[i][j]=3;
        count++;
    }
    //up-right
    for(int i=r_q-1,j=c_q+1;i>=0,j<n;i--,j++){
        if(board[i][j]){
            break;
        }
        board[i][j]=3;
        count++;
    }
    //down-left
    for(int i=r_q+1,j=c_q-1;i<n,j>=0;i++,j--){
        if(board[i][j]){
            break;
        }
        board[i][j]=3;
        count++;
    }
    //down-right
    for(int i=r_q+1,j=c_q+1;i<n,j<n;i++,j++){
        if(board[i][j]){
            break;
        }
        board[i][j]=3;
        count++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return count;

}
int main(){

ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    uint64_t result = queensAttack(n, k, r_q, c_q, obstacles);

    cout<< result << "\n";

    fout.close();

    return 0;
}

