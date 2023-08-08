// 16236 아기상어
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int sharkX, sharkY;
int sharkSize=2;
int eatCnt;
int n;
int ans;

class Map{
public:
    int x,y;
    int value;
    int dis;

    void setMap(int y, int x, int value){
        this->y = y;
        this->x = x;
        this->dis = -1;

        if(value <= 6){
            this->value = value;
        }else if(value == 9){
            this->value = 0;
            sharkY = y;
            sharkX = x;
        }
    }
};

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

Map map[21][21];

int minDis;
int minY, minX;

bool canVisit(int ny, int nx){
    return (map[ny][nx].dis<0 && sharkSize >= map[ny][nx].value && nx >= 0 && nx < n && ny >= 0 && ny < n);
}

bool canEat(int ny, int nx){
    return (map[ny][nx].value != 0 && sharkSize > map[ny][nx].value);
}



void bfs(){
    queue<Map> q;
    map[sharkY][sharkX].dis = 0;                // 시작위치
    q.push(map[sharkY][sharkX]);

    int nx, ny;
    Map v;

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)){
                map[ny][nx].dis = v.dis + 1;

                if(canEat(ny, nx)){                                 // 물고기가 있고 먹을 수 있는 크기라면 가까운지 확인해야함

                    if(minDis > map[ny][nx].dis){                   // 더 가깝다면 min값 바꾸기
                        minDis = map[ny][nx].dis;
                        minY = ny;
                        minX = nx;
                    }else if(minDis == map[ny][nx].dis){            // 거리가 같다면 맨 위, 맨 왼쪽 물고기 찾기
                        if(minY > ny){              // 맨 위
                            minY = ny;
                            minX = nx;
                        }else if(minY == ny){       // y가 같다면
                            if(minX > nx){          // 맨 왼쪽 (x가 작은 거 선택)
                                minY = ny;
                                minX = nx;
                            }
                        }
                    }
                }
                q.push(map[ny][nx]);
            }   
        }
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    int temp;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>temp;
            map[i][j].setMap(i, j, temp);
        }
    }

    while(true){
        minDis = 500;       // 가장 가까운 물고기까지 거리
        minY = 21;          // 가장 가까운 물고기의 y
        minX = 21;          // 가장 가까운 물고기의 x

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                map[i][j].dis = -1;         // 거리 초기화
            }
        }
        
        bfs();

        if(minX != 21 && minY != 21){       // 먹을 물고기 찾음
            ans += map[minY][minX].dis;     
            eatCnt++;

            map[minY][minX].value = 0;      // 빈 칸으로

            sharkY = minY;                  // 상어 위치 이동
            sharkX = minX;

            if (eatCnt >= sharkSize){       // 크기 키우기
                eatCnt = 0;
                sharkSize++;
            }
        }else{
            break;
        }
    }

    cout << ans;
}
