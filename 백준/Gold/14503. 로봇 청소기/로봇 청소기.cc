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
int node[51][51];
bool isClean[51][51];

int r, c, d;

int cnt;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int nr, int nc){
    return (nr >= 0 && nr < n && nc >= 0 && nc < m && node[nr][nc] == 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> r >> c >> d;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> node[i][j];
        }
    }

    bool play = true;

    while(play){
        if(!isClean[r][c]){
            isClean[r][c] = true;   // 현재 칸 청소
            cnt++;
        }

        int nr, nc;

        bool flag = false;
        for(int i = 0; i<4; i++){
            nr = r + dir[i][0];
            nc = c + dir[i][1];
            if(canVisit(nr, nc) && !isClean[nr][nc]){
                flag = true;        // 청소 안 된 빈칸 있음
                break;
            }
        }

        if(!flag){      // 후진
            if(d == 0 && canVisit(r+1, c)){
                r++;
            }else if(d == 1 && canVisit(r, c-1)){
                c--;
            }else if(d == 2 && canVisit(r-1, c)){
                r--;
            }else if(d == 3 && canVisit(r, c+1)){
                c++;
            }else{
                play = false;
                // break;      // 작동 멈춰
            }
        }else{
            // 회전
            d = (d + 3) % 4;
            if(d == 0 && !isClean[r-1][c] && canVisit(r-1, c)){
                r--;
            }else if(d == 1 && !isClean[r][c+1] && canVisit(r, c+1)){
                c++;
            }else if(d == 2 && !isClean[r+1][c] && canVisit(r+1, c)){
                r++;
            }else if(d == 3 && !isClean[r][c-1] && canVisit(r, c-1)){
                c--;
            }
        }
    }

    cout << cnt;
}


