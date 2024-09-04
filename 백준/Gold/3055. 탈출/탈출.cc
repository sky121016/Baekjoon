// 3055
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


class Node{
public:
    int y, x;
    bool visited;
    int dis;
    char value;

    void setNode(int y, int x, char v){
        this->y = y;
        this->x = x;
        value = v;
        dis = 3000;
        visited = false;
    }

};

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};


int r,c;
Node node[51][51];

queue<Node> wq;

int sy, sx;

bool canVisit(int ny, int nx){
    return (!node[ny][nx].visited && ny >= 0 && ny < r && nx >= 0 && nx < c);
}


void wbfs(){
    
    Node v;

    int ny, nx;

    while(!wq.empty()){
        v = wq.front();
        wq.pop();

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if (canVisit(ny, nx) && v.dis + 1 < node[ny][nx].dis && node[ny][nx].value != 'D' && node[ny][nx].value != 'X'){
                node[ny][nx].visited = true;
                node[ny][nx].dis = v.dis + 1;
                wq.push(node[ny][nx]);
            }
        }
    }
}


void resetVisited(){
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            node[i][j].visited = false;
        }
    }

    node[sy][sx].dis = 0;
}

int ans;


bool sbfs(){
    queue<Node> q;

    node[sy][sx].visited = true;
    q.push(node[sy][sx]);

    Node v;
    int ny, nx;

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx) && v.dis + 1 < node[ny][nx].dis && node[ny][nx].value != 'X'){
                node[ny][nx].visited = true;
                node[ny][nx].dis = v.dis + 1;
                q.push(node[ny][nx]);

                if(node[ny][nx].value == 'D'){
                    ans = node[ny][nx].dis;
                    return true;
                }
            }
        }
    }

    return false;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    char temp;
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);

            if(temp == '*'){
                node[i][j].visited = true;
                node[i][j].dis = 0;
                wq.push(node[i][j]);
            }else if(temp == 'S'){
                sy = i;
                sx = j;
            }
        }
    }



    wbfs();

    resetVisited();

    if(sbfs()){
        cout << ans;
    }else{
        cout<<"KAKTUS";
    }


}
