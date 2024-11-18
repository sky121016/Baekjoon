#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;



int r, c, t;
int map[52][52];
int newMap[52][52];
int up, down;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};


bool canDiffuse(int ny, int nx){
    return (ny > 0 && ny <= r && nx > 0 && nx <= c);
}

bool isAirPurifier(int y, int x){
    return(map[y][x] == -1);
}

void diffuseEach(int y, int x){
    int ny, nx;
    int cnt = 0;
    int add = map[y][x] / 5;

    for(int i = 0; i<4; i++){
        ny = y + dir[i][0];
        nx = x + dir[i][1];

        if(canDiffuse(ny, nx) && !isAirPurifier(ny, nx)){
            newMap[ny][nx] += add;
            cnt++;
        }
    }

    newMap[y][x] += map[y][x] - (cnt * add);
}

void diffusion(){
    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c; j++){
            if(map[i][j] > 0){
                diffuseEach(i, j);
            }
        }
    }
}


void reset(){
    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c; j++){
            map[i][j] = newMap[i][j];
            newMap[i][j] = 0;
        }
    }

    map[up][1] = -1;
    map[down][1] = -1;

}


void print(){
    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c; j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}


void rotate(){
    //upside
    // i 행    j 열
    // 1열 up-1행
    for(int i = up-2; i>0; i--){
        map[i+1][1] = map[i][1];
    }

    // 1행
    for(int j = 2; j<=c; j++){
        map[1][j-1] = map[1][j];
    }

    // 마지막열
    for(int i = 2; i<=up; i++){
        map[i-1][c] = map[i][c];
    }

    // Up행
    for(int j = c-1; j>=2; j--){
        map[up][j+1] = map[up][j]; 
    }

    //downside

    // 1열 down+1행
    for(int i = down+2; i<=r; i++){
        map[i-1][1] = map[i][1];
    }

    // 마지막행
    for(int j = 2; j<=c; j++){
        map[r][j-1] = map[r][j];
    }

    // 마지막열
    for(int i = r-1; i>=down; i--){
        map[i+1][c] = map[i][c];
    }

    // Down행
    for(int j = c-1; j>=2; j--){
        map[down][j+1] = map[down][j]; 
    }

    map[up][2] = 0;
    map[down][2] = 0;

}


int getDust(){
    int sum = 0;
    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c; j++){
            if(map[i][j] == -1){
                continue;
            }
            sum += map[i][j];
        }
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> t;

    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c; j++){
            cin >> map[i][j];

            if(map[i][j] == -1 && up == 0){
                up = i;
                down = up + 1;
            }

        }
    }

    while(t > 0){
        diffusion();

        reset();

        rotate();

        t--;
    }

    cout << getDust();
}

