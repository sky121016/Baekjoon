// 14502
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int r, c;

int minDis = 1000000;

class Node{
public:
    int y, x;
    bool visited[3];
    int dis[3];
    char value;


    void setNode(int y, int x, char v){
        this->y = y;
        this->x = x;
        value = v;
        visited[0] = false;
        visited[1] = false;
        visited[2] = false;

        dis[0] = 100000;
        dis[1] = 100000;
        dis[2] = 100000;
    }

 
};

Node node[101][101];


int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx, int num){
    return(!node[ny][nx].visited[num] && ny>0 && ny<=r && nx>0 && nx<=c && node[ny][nx].value == '0');
}

void bfs(Node& V, int num){
    queue<Node> q;

    V.visited[num] = true;
    V.dis[num] = 0;

    q.push(V);

    Node v;
    int ny, nx;

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx, num)){
                node[ny][nx].dis[num] = v.dis[num] + 1;
                node[ny][nx].visited[num] = true;
                q.push(node[ny][nx]);
            }
        }
    }
}

int totalDis[101][101];
int cnt;
int ans;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    char temp;
    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
        }
    }

    int y, x;
    for(int num = 0; num<3; num++){
        cin >> y >> x;
        bfs(node[y][x], num);


    }

    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c; j++){
            if(node[i][j].visited[0] && node[i][j].visited[1] && node[i][j].visited[2]){
                totalDis[i][j] = max(max(node[i][j].dis[0], node[i][j].dis[1]), node[i][j].dis[2]);

                if(minDis > totalDis[i][j]){
                    minDis = totalDis[i][j];
                }
            }

        }
    }

    if(minDis < 1000000){
        for(int i = 1; i<=r; i++){
            for(int j = 1; j<=c; j++){
                if(totalDis[i][j] == minDis){
                    cnt ++;
                }

            }
        }


        cout<<minDis<<"\n"<<cnt;
    }else{
        cout << -1;
    }

    
}