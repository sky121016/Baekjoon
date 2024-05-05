// 2580
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>

using namespace std;

int map[10][10];
int r[10][10];
int c[10][10];
int block[10][10];


int dfs(int y, int x, int cnt){
    if(cnt == 81){
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                cout<<map[i][j]<<" ";
            }
            cout << "\n";
        }

        return 1;

    }else{
        int ny, nx;
        ny = y;
        nx = (x + 1) % 9;
        if (nx == 0){
            ny++;
        }

        if(map[y][x] == 0){
            for(int i = 1; i<=9; i++){
                if (r[y][i] == 0 && c[x][i] == 0 && block[(y / 3) * 3 + x / 3][i] == 0){
                    r[y][i] = 1;
                    c[x][i] = 1;
                    block[(y / 3) * 3 + x / 3][i] = 1;
                    map[y][x] = i;

                    
                    if(dfs(ny, nx, cnt+1) == 1){
                        return 1;
                    }

                    r[y][i] = 0;
                    c[x][i] = 0;
                    block[(y / 3) * 3 + x / 3][i] = 0;
                    map[y][x] = 0;
                }
            }
        }else{
            if(dfs(ny, nx, cnt+1) == 1){
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


    int k;
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cin >> k;
            map[i][j] = k;
            r[i][k] = 1;
            c[j][k] = 1;
            block[(i / 3) * 3 + j / 3][k] = 1;
        }
    }

    dfs(0, 0, 0);
}


