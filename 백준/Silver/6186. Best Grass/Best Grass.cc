#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

using namespace std;

class Node{
public:
    int x, y;
    bool visited;
    char v;

    void setNode(int y, int x, char v){
        this->y = y;
        this->x = x;
        this->v = v;
        visited = false;
    }
};

int r, c;
Node node[101][101];


int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

bool canVisit(int ny, int nx){
    return !node[ny][nx].visited && ny > 0 && ny <= r && nx > 0 && nx <= c && node[ny][nx].v != '.';
}

void bfs(int y, int x){
    queue<Node> q;
    node[y][x].visited = true;
    q.push(node[y][x]);


    Node v;

    while(!q.empty()){
        v = q.front();
        q.pop();
        
        int next;
        for(int i = 0; i<4; i++){
            int ny;
            int nx;

            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];


            if(canVisit(ny, nx)){
                node[ny][nx].visited = true;
                q.push(node[ny][nx]);
                
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    char temp;
    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c; j++){
            cin>>temp;
            node[i][j].setNode(i, j, temp);
        }
    }

    int cnt = 0;

    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c; j++){
            if(!node[i][j].visited && node[i][j].v =='#'){
                bfs(i, j);
                cnt++;
            }

        }
    }

    cout<<cnt;




}