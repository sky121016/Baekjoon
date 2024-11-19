#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

class Node{
public:
    int y, x;
    int color;
    int cnt;

    void setNode(int y, int x, int c){
        this->y = y;
        this->x = x;
        color = c;
        cnt = 99999999;
    }


};

int n;

Node node[51][51];


int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return (ny > 0 && ny <= n && nx > 0 && nx <= n);
}

void bfs(){
    queue<Node> q;
    node[1][1].cnt = 0;
    q.push(node[1][1]);
    
    int ny, nx;
    int cnt;

    Node v;
    while(!q.empty()){
        v = q.front();

        q.pop();

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)){
                if(node[ny][nx].color == 1){
                    if(node[ny][nx].cnt > v.cnt){
                        node[ny][nx].cnt = v.cnt;
                        q.push(node[ny][nx]);
                    }
                }else{
                    if(node[ny][nx].cnt > v.cnt+1){
                        node[ny][nx].cnt = v.cnt+1;
                        q.push(node[ny][nx]);
                    }
                }
            }
        }
    }

  
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    char temp;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp-'0');
        }
    }

    bfs();

    cout<<node[n][n].cnt;

}
