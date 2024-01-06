// 1743
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m;
int k;

class Node{
public:
    int x, y;
    bool visited;
    int trash;
    void setNode(int y, int x){
        this->y = y;
        this->x = x;
        visited = false;
        trash = 0;
    }

    void setTrashNode(){
        trash = 1;
    }
};

Node node[101][101];

int maxTrashSize = 0;
int tempSize;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

bool canVisit(int ny, int nx){
    return (!node[ny][nx].visited && node[ny][nx].trash == 1 && ny <= n && ny > 0 && nx <= m && nx > 0);
}

void bfs(Node& v){
    queue<Node> q;
    v.visited = true;
    q.push(v);

    tempSize = 1;

    while(!q.empty()){
        v = q.front();
        q.pop();
        
        int ny, nx;

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if (canVisit(ny, nx)){
                node[ny][nx].visited = true;
                q.push(node[ny][nx]);
                tempSize ++;
            }
        }
    }

    if(maxTrashSize < tempSize){
        maxTrashSize = tempSize;
    }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            node[i][j].setNode(i, j);
        }
    }

    
    int r, c;
    for(int i = 0; i<k; i++){
        cin >> r >> c;
        node[r][c].setTrashNode();
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if (canVisit(i, j)){
                bfs(node[i][j]);
            }
        }
    }

    cout << maxTrashSize;
}

