// 1303
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int N, M;
int total[2];

class Node{
public:
    int y, x;
    int color;      // W:0 B:1
    bool visited;

    void setNode(int y, int x, char c){
        this->y = y;
        this->x = x;

        if (c == 'W'){
            color = 0;
        }else{
            color = 1;
        }
        visited = false;
    }
};

Node node[101][101];
int cnt;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return(!node[ny][nx].visited && ny>=0 && ny<M && nx>=0 && nx<N);
}

void dfs(Node& V){
    int ny, nx;
    V.visited = true;
    
    for(int i = 0; i<4; i++){
        ny = V.y + dir[i][0];
        nx = V.x + dir[i][1];

        if(canVisit(ny, nx) && node[ny][nx].color == V.color){
            cnt++;
            dfs(node[ny][nx]);
        }
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    char temp;
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
        }
    }

    
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            if(!node[i][j].visited){
                cnt = 1;
                dfs(node[i][j]);
                total[node[i][j].color] += cnt * cnt;
            }
        }
    }

    cout << total[0] << " " << total[1];
}


