// 2109
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;


int board[16];
int n;
int ans;

bool canPut(int cnt){
    for(int i = 1; i<cnt; i++){
        if(board[cnt] == board[i] || cnt-i == abs(board[cnt]-board[i])){
            return false;
        }
    }
    return true;

}

void dfs(int cnt){
    if(cnt == n+1){
        ans ++;
        return;
    }else{
        for(int i = 1; i<=n; i++){
            board[cnt] = i;
            if(canPut(cnt)){
                dfs(cnt+1);
            }
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    dfs(1);
    
    cout << ans;
}
