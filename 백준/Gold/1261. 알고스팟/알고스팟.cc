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
    int y, x;
    char value;
    int cnt;

    void setNode(int y, int x, char v){
        this->y = y;
        this->x = x;
        value = v;
        cnt = 9999999;
    }
};

int n, m;
Node node[101][101];
int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return (ny > 0 && ny <= n && nx > 0 && nx <= m);
}

void bfs(){
    queue<Node> q;
    node[1][1].cnt = 0;
    q.push(node[1][1]);

    Node v;
    while(!q.empty()){
        v = q.front();
        q.pop();

        int ny, nx;
        for (int i = 0; i < 4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            
            if(canVisit(ny, nx)){
                // cout << ny << " " << nx << "\n";
                if(node[ny][nx].value == '0' && v.cnt < node[ny][nx].cnt){
                    node[ny][nx].cnt = v.cnt;
                    q.push(node[ny][nx]);
                }else if(node[ny][nx].value == '1' && v.cnt + 1 < node[ny][nx].cnt){
                    node[ny][nx].cnt = v.cnt + 1;
                    q.push(node[ny][nx]);
                }
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;

    char temp;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
        }
    }

    bfs();

    cout << node[n][m].cnt;
}

