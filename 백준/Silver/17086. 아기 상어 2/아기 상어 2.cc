// 17086
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Node{
public:
    int x, y;
    int shark;
    bool visited;
    int dis;

    void setNode(int y, int x, int s){
        this->y = y;
        this->x = x;
        shark = s;
        visited = false;

        if(s == 1){
            dis = 0;
        }else{
            dis = 3000;
        }
    }

};


int n, m;
Node node[51][51];

int dir[8][2] = {
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1},
    {-1, -1},
};


bool canVisit(int ny, int nx){
    return (!node[ny][nx].visited && ny >= 0 && ny < n && nx >= 0 && nx < m);
}

queue<Node> q;
void bfs(){
    Node v;    

    while(!q.empty()){
        v = q.front();
        q.pop();

        int ny, nx;
        for(int i = 0; i<8; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)){
                node[ny][nx].visited = true;
                node[ny][nx].dis = min(node[ny][nx].dis, v.dis + 1);
                // cout << ny << " " << nx << " " << node[ny][nx].dis << "\n";
                q.push(node[ny][nx]);
            }
        }
    }


}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int temp;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
            if(temp == 1){
                node[i][j].visited = true;
                q.push(node[i][j]);
            }
        }
    }

    bfs();
    
    int maxDis = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(maxDis < node[i][j].dis){
                maxDis = node[i][j].dis;
            }
        }
    }

    cout << maxDis;
}



