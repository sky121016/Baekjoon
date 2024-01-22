// 16236
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int curX, curY;


class Node{
public:
    int x, y;
    int value;

    int dis;

    void setNode(int y, int x, int v){
        this->y = y;
        this->x = x;
        if(v==9){
            value = 0;
            curY = y;
            curX = x;
        }else{
            value = v;
        }
        dis = -1;

    }

    void initNode(){
        dis = -1;
    }
};


int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

int n;
Node node[21][21];

int sharkSize;
int ans;
int eatCnt;

int minDis;
int minX, minY;


bool canVisit(int ny, int nx){
    return (node[ny][nx].dis < 0 && node[ny][nx].value <= sharkSize && ny < n && ny >= 0 && nx < n && nx >= 0);
}

bool canEat(int ny, int nx){
    return (node[ny][nx].value < sharkSize && node[ny][nx].value != 0);
}


void bfs(){
    queue<Node> q;
    Node v;
    node[curY][curX].dis = 0;

    q.push(node[curY][curX]);

    while(!q.empty()){
        v = q.front();
        q.pop();

        int ny, nx;
        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if (canVisit(ny, nx)){
                node[ny][nx].dis = v.dis + 1;

                if (canEat(ny, nx)){
                    if(minDis > node[ny][nx].dis){
                        minDis = node[ny][nx].dis;
                        minY = ny;
                        minX = nx;

                    }else if(minDis == node[ny][nx].dis){
                        if(minY > ny){
                            minY = ny;
                            minX = nx;
                        }else if(minY == ny){
                            if (minX > nx){
                                minY = ny;
                                minX = nx;
                            }
                        }
                    }
                }
                q.push(node[ny][nx]);
            }
        }
    }
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int temp;
    sharkSize = 2;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
        }
    }


    while(true){
        minDis = 500;
        minX = 21;
        minY = 21;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                node[i][j].initNode();
            }
        }

        bfs();

        if(minX != 21 && minY != 21){
            ans += minDis;
            node[minY][minX].value = 0;
            eatCnt ++;

            curX = minX;
            curY = minY;

            if(eatCnt == sharkSize){
                eatCnt = 0;
                sharkSize++;
            }
        }else{
            break;
        }

    }

    cout << ans;
}
