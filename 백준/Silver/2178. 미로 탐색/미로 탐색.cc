// 2178 미로
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stdio.h>
using namespace std;


class Node{
public:
    int x,y,dir;
    int dis;
    bool visited;
    void setNode(int y, int x){
        this->x = x;
        this->y = y;
        visited = false;
    }
};

int n,m;
char maze[101][101];
Node node[101][101];

int dir[4][2] = {
    {-1,0},
    {0,1},
    {1,0},
    {0,-1}
};

bool canVisit(int ny, int nx){
    return (maze[ny][nx] == '1' && !node[ny][nx].visited && nx >= 0 && nx < m && ny >= 0 && ny < n);
}

void bfs(Node& v){
    queue<Node> q;
    q.push(v);
    v.visited = true;

    int nx, ny;
    
    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(maze[ny][nx]== '1' && canVisit(ny, nx)){
                node[ny][nx].visited = true;
                node[ny][nx].dis = v.dis + 1;
                q.push(node[ny][nx]);
            }
        }
    }    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;

    for(int i = 0; i<n; i++){
        cin>>maze[i];
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            node[i][j].setNode(i,j);
        }
    }

    node[0][0].visited = true;
    node[0][0].dis = 1;

    bfs(node[0][0]);

    // cout << node[0][0].dis << endl;
    cout << node[n - 1][m - 1].dis << endl;
}

