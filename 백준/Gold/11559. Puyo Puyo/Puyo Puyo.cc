// 뿌요뿌요
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Map{
public:
    int x, y;
    char value;

    void setMap(int y, int x, char c){
        this->y = y;
        this->x = x;    
        value = c;
    }
};

Map map[12][6];
bool explo;           // 터지면 true   
bool visited[12][6];


int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

bool canVisit(int ny, int nx){
    return (!visited[ny][nx] && nx >= 0 && nx < 6 && ny >= 0 && ny < 12);
}

queue<Map> group;            // 터지는 블럭
int result;
int blockCnt;


void explosion(){
    Map v;
    while(!group.empty()){
        v = group.front();
        group.pop();
        map[v.y][v.x].value = '.';        // 터진 곳은 . 넣어주기
    }
}

void bfs(Map& start){
    queue<Map> q;
    q.push(start);
    group.push(start);
    visited[start.y][start.x] = true;   

    blockCnt = 1;


    Map v;
    int ny, nx;
    

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx) && v.value == map[ny][nx].value){
                q.push(map[ny][nx]);
                group.push(map[ny][nx]);
                
                visited[ny][nx] = true;
                blockCnt++;
            }
        }
    }

    if(blockCnt >= 4){          // 터짐
        explosion();
        explo = true;
    }else{
        group = queue<Map>();
    }
}


void move(){
    queue<char> tq;
    char temp;

    for(int j = 0; j<6; j++){
        for(int i = 11; i>=0; i--){
            if(map[i][j].value != '.'){        // 이동해야할 뿌요 큐에 저장
                tq.push(map[i][j].value);
            }
        }

        for(int i = 11; i>=0; i--){
            map[i][j].value = '.';            // 모두 .으로 초기화
        }

        int k = 11;
        while(!tq.empty()){                    // 저장한 뿌요들 밑에서부터 넣어주기
            temp = tq.front();
            tq.pop();
            map[k][j].value = temp;
            k--;
        }
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    char c;

    for(int i = 0; i<12; i++){
        for(int j = 0; j<6; j++){
            cin >> c;
            map[i][j].setMap(i, j, c);
        }
    }

    while(true){
        for(int i = 0; i<12; i++){
            for(int j = 0; j<6; j++){
                if(map[i][j].value != '.' && !visited[i][j]){
                    bfs(map[i][j]);
                }
            }
        }

        if(explo){                // 터졌으면
            move();
            result ++;
            blockCnt = 1;
            explo = false;

            for(int i = 0; i<12; i++){
                memset(visited[i], false, sizeof(bool)*12);
            }

        }else{
            break;
        }
    }

    cout<<result;
}
