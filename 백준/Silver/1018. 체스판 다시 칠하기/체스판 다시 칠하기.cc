#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

int n, m;
int mask[8][8];
int board[51][51];
int ans = 99999999;
int minVal;

void window(int y, int x){
    int cnt1 = 0;
    int cnt2 = 0;

    // W 부터 시작
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if(board[y+i][x+j] != mask[i][j]){
                cnt1++;
            }
        }
    }

    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if(board[y+i][x+j] == mask[i][j]){
                cnt2++;
            }
        }
    }


    minVal = min(cnt1, cnt2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if(i % 2 == 0 && j % 2 == 0){
                mask[i][j] = 1;
            }else if(i % 2 == 1 && j % 2 == 1){
                mask[i][j] = 1;
            }
        }
    }
 

    cin >> n >> m;
    char temp;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>temp;
            if(temp == 'W'){
                board[i][j] = 1;
            }
        }
    }


    for(int i = 0; i<=n-8; i++){
        for(int j = 0; j<=m-8; j++){
            window(i, j);

            ans = min(minVal, ans);
        }
    }

    cout << ans;
}

