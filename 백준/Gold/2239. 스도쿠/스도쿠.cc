// 2239
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>

using namespace std;

int r[10][10];
int c[10][10];
int box[10][10];
int board[10][10];

int sudoku(int y, int x, int cnt){
    if(cnt == 81){
        for(int i =0 ; i<9; i++){
            for(int j = 0; j<9; j++){
                cout<<board[i][j];
            }
            cout<<"\n";
        }
        return 1;
    }else{
        int ny = y;
        int nx = (x + 1) % 9;

        if(nx == 0){
            ny++;
        }

        // cout << y << x<<"\n";
        if(board[y][x] == 0){
            for(int i = 1; i<= 9; i++){
                if (r[y][i] == 0 & c[x][i] == 0 && box[(y / 3) * 3 + x/3][i] == 0){
                    r[y][i] = 1;
                    c[x][i] = 1;
                    box[(y / 3) * 3 + x/3][i] = 1;
                    board[y][x] = i;

                    if(sudoku(ny, nx, cnt+1) == 1){
                        return 1;
                    }

                    r[y][i] = 0;
                    c[x][i] = 0;
                    box[(y / 3) * 3 + x/3][i] = 0;
                    board[y][x] = 0;
                }
            }
        }else{
            if(sudoku(ny, nx, cnt + 1) == 1){
                return 1;
            }
        }
    }

    return 0;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char temp;
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cin >> temp;
            int k = temp-'0';
            board[i][j] = k;
            r[i][k] = 1;
            c[j][k] = 1;
            box[(i / 3) * 3 + j / 3][k] = 1;
        }
    }

    if(sudoku(0, 0, 0) == 1){
        return 0;
    }

    return 0;
}
