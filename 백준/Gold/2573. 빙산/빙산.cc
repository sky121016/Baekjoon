// 2357

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

class Node{
public:
    int y, x;
    bool visited;
    int value;
    int ice;

    void setNode(int y, int x, int v){
        this->y = y;
        this->x = x;
        value = v;
        visited = false;
        ice = 0;
    }
};

int n, m;
int cnt;
int year;
Node node[310][310];

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return (ny > 0 && ny <= n && nx > 0 && nx <= m && !node[ny][nx].visited && node[ny][nx].value > 0);
}


void countIce(int y, int x){
    int ny, nx;

    for(int i = 0; i<4; i++){
        ny = y + dir[i][0];
        nx = x + dir[i][1];
        if(node[ny][nx].value <= 0){
            node[y][x].ice ++;            
        }
    }
}


void print(){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cout<<node[i][j].value<<" ";
        }
        cout<<"\n";
    }
}

void bfs(Node& V){
    queue<Node> q;

    V.visited = true;
    q.push(V);

    Node v;
    int ny, nx;

    while(!q.empty()){
        v = q.front();
        q.pop();

        countIce(v.y, v.x);

        for(int i = 0; i<4; i++){
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

    cin >> n >> m;

    int temp;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
        }
    }

    year = -1;


    while(true){
        cnt = 0;

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(!node[i][j].visited && node[i][j].value > 0){
                    bfs(node[i][j]);
                    cnt++;
                }
            }
        }

        // melt
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(node[i][j].value > 0){
                    node[i][j].value -= node[i][j].ice;
                }
                node[i][j].ice = 0;
                node[i][j].visited = false;
            }
        }
        
        year++;

        if(year > 0 && cnt == 0){
            year = 0;
            break;
        }

        if(cnt > 1 || cnt == 0){
            break;
        }

        
    }

    if(year < 0){
        cout << '0';
    }else{
        cout << year;
    }
}
