// 14503 로봇청소기
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int dir;
int x, y, nx, ny;
int cnt;
int map[51][51];
bool visited[51][51];
bool Finish;
int rotation;

int Move[4][2] = {      // 현재 위치에   + : 전진 ,     - : 후진
    {-1, 0},            // 북
    {0, 1},             // 동
    {1, 0},             // 남
    {0, -1}             // 서
};


void robot(){
    visited[y][x] = 1;          // 시작 위치 방문 체크
    cnt++;

    while(y<n && y>=0 && x<m && x >= 0){
        Finish = true;

        for(int i = 0; i<4; i++){           // 청소 안 된 남은 칸 확인
            ny = y + Move[i][0];
            nx = x + Move[i][1];
            if(map[ny][nx] == 0 && !visited[ny][nx]){     // 청소되지 않은 빈 칸 남은 경우
                Finish = false;
                break;
            }
        }

        if(Finish){                         // 청소되지 않은 빈 칸 없는 경우 -> 후진
            ny = y - Move[dir][0];
            nx = x - Move[dir][1];

            y = ny;
            x = nx;

            if(map[ny][nx] == 1){     // 벽 있어서 작동 멈춤
                return;
            }

        }else{                                              // 청소되지 않은 빈 칸 남은 경우 -> 전진
            while(rotation < 4){
                dir = (dir + 3) % 4;                        // 반시계 회전
                rotation++;

                ny = y + Move[dir][0];                      // 전진
                nx = x + Move[dir][1];

                if(map[ny][nx] == 0 && !visited[ny][nx]){
                    visited[ny][nx] = true;
                    y = ny;
                    x = nx;
                    cnt++;
                    rotation = 0;
                    break;
                }
            
            }                             

        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> m;
    cin >> y >> x >> dir;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
        }
    }


    robot();
    cout<<cnt;

}
