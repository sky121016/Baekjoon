// 3190 뱀
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Map{
public:
    int x, y;
    bool apple;

    void setMap(int y, int x){
        this->y = y;
        this->x = x;
        apple = false;
    }
};


int N, K, L;
int X;
char C;
Map map[101][101];
char changeDir[10001];      // 방향 전환
int cnt;                    // 초

bool body[101][101];        // 뱀의 몸이 있는지

int dir[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}    
};

int nDir;


void changeDirection(){
    if(changeDir[cnt] == 'D'){
        nDir = (nDir + 1) % 4;
    }else if(changeDir[cnt] == 'L'){
        nDir = (nDir + 3) % 4;
    }
}

bool Wall(int ny, int nx){
    return (nx < 1 || nx > N || ny < 1 || ny > N);
}

bool Body(int ny, int nx){
    return (body[ny][nx]);
}


int Dummy(){
    queue<Map> q;
    q.push(map[1][1]);
    body[1][1] = true;

    int ny, nx;
    Map tail;
    Map head;
    head = map[1][1];

    while(1){
        tail = q.front();

        ny = head.y + dir[nDir][0];
        nx = head.x + dir[nDir][1];
        head = map[ny][nx];                    // 큐의 마지막

        q.push(head);
    


        // 벽 or 몸 충돌
        if(Wall(ny, nx) || Body(ny, nx)){return cnt+1;}

        // 사과
        if(map[ny][nx].apple){                    // 사과 있으면 사과 없애기
            map[ny][nx].apple = false;
        }else{
            q.pop();                              // 꼬리 없애기
            body[tail.y][tail.x] = false;         
        }



        body[ny][nx] = true;
        cnt++;
        
        
        // 방향 전환
        changeDirection();
        
    }
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            map[i][j].setMap(i,j);
        }
    }

    int ty, tx;
    for(int i = 0; i<K; i++){
        cin >> ty >> tx;
        map[ty][tx].apple = true;
    }

    cin >> L;

    for(int i = 0; i<L; i++){
        cin >> X >> C;
        changeDir[X] = C;
    }

    cout<<Dummy()<<"\n";


}



