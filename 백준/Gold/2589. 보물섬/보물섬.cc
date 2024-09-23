// 13398
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

class Node{
public:
    int y, x;
    bool visited;
    char value;
    int dis;

    void setNode(int y, int x, char v){
        this->y = y;
        this->x = x;
        value = v;
        visited = false;
        dis = 0;
    }

};

int w, h;
Node node[51][51];
int maxDis;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return (!node[ny][nx].visited && ny>=0 && ny<w && nx>=0 && nx<h && node[ny][nx].value == 'L');
}


void bfs(Node& V){
    queue<Node> q;
    V.visited = true;
    V.dis = 0;
    q.push(V);

    Node v;
    int ny, nx;

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)){
                node[ny][nx].visited = true;
                node[ny][nx].dis = v.dis+1;
                q.push(node[ny][nx]);

                if(maxDis < node[ny][nx].dis){
                    maxDis = node[ny][nx].dis;
                }
            }
        }
    }
}


void reset(){
    for(int i = 0; i<w; i++){
        for(int j = 0; j<h; j++){
            node[i][j].visited = false;
            node[i][j].dis = 0;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> w >> h;

    char c;
    for(int i = 0; i<w; i++){
        for(int j = 0; j<h; j++){
            cin >> c;
            node[i][j].setNode(i, j, c);
        }
    }

    
    for(int i = 0; i<w; i++){
        for(int j = 0; j<h; j++){
            if(node[i][j].value == 'L'){
                bfs(node[i][j]);
                reset();
            }
        }
    }

    cout<<maxDis;

}