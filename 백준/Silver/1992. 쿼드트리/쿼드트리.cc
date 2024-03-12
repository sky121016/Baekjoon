// 1992
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;
char map[65][65];
char first;
queue<char> q;
bool flag = true;


void quad(int n, int y, int x){
    flag = true;
    
    if(n == 1){
        q.push(map[y][x]);
        return ;
    }else{
        first = map[y][x];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(map[y+i][x+j] != first){
                    flag = false;
                    break;
                }
            }
        }

        if(flag == true){
            q.push(first);
            return;
        }else{
            q.push('(');
            quad(n / 2, y, x);
            quad(n / 2, y, x + n / 2);
            quad(n / 2, y + n / 2, x);
            quad(n / 2, y + n / 2, x + n / 2);
        }
    }
    q.push(')');

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;


    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> map[i][j];
        }
    }


    quad(N, 0, 0);

    while(!q.empty()){
        cout<<q.front();
        q.pop();
    }

}
