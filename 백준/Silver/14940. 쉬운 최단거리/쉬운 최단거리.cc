// 14940
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;



class Node{
public:
    int x,y;
    bool visited;
    int dis;
    int value;

    void setNode(int y, int x, int value){
        this->y = y;
        this->x = x;
        this->value = value;

        if(value == 0){
            dis = 0;
        }else{
            dis = -1;
        }
        visited = false;
    }
};


Node node[1001][1001];
int n, m;

int startY, startX;


int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

bool canVisit(int ny, int nx){
    return (!node[ny][nx].visited && node[ny][nx].value != 0 && ny > 0 && ny <= n && nx > 0 && nx <= m);
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
                node[ny][nx].dis = v.dis + 1;
                node[ny][nx].visited = true;
                q.push(node[ny][nx]);
            }
        }

    }
}



void answer(){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cout<<node[i][j].dis<<" ";
        }
        cout<<"\n";
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
            node[i][j].setNode(i,j, temp);

            if(temp == 2){
                startY = i;
                startX = j;
            }
        }
    }

    bfs(node[startY][startX]);

    answer();





}