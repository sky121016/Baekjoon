// 17086
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Node{
public:
    int x, y;
    int value;
    bool visited;
    int dis;
    void setNode(int y, int x, int v){
        this->y = y;
        this->x = x;
        value = v;
        dis = 0;
        visited = false;
    }
};

Node node[5][5];
int r, c;
int ans = -1;

bool canVisit(int ny, int nx){
    return (!node[ny][nx].visited && node[ny][nx].value != -1 && ny >= 0 && ny < 5 && nx >= 0 && nx < 5);
}

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

void bfs(Node& v){
    queue<Node> q;
    v.visited = true;
    q.push(v);

    while(!q.empty()){
        v = q.front();
        q.pop();


        int ny, nx;
        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)){
                node[ny][nx].visited = true;
                node[ny][nx].dis = v.dis + 1;
                q.push(node[ny][nx]);

                if(node[ny][nx].value == 1){
                    ans = node[ny][nx].dis;
                    return;
                }
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int temp;
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
        }
    }

    cin >> r >> c;

    bfs(node[r][c]);


    cout << ans;

}


