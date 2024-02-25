// 2109
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

class Node{
public:
    int y, x;
    int value;
    bool visited;
    int island;
    int dis;
    void setNode(int y, int x, int v){
        this->y = y;
        this->x = x;
        value = v;
        visited = false;
        island = 0;
        dis = 0;
    }

    void setVisited(){
        visited = false;
    }
};

int n;
Node node[101][101];

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

bool canVisit(int ny, int nx){
    return (!node[ny][nx].visited && ny >= 0 && ny < n && nx >= 0 && nx < n);
}

void bfs(Node& v){
    queue<Node> q;
    v.visited = true;
    q.push(v);

    Node u;

    while(!q.empty()){
        u = q.front();
        q.pop();

        int ny, nx;

        for(int i = 0; i<4; i++){
            ny = u.y + dir[i][0];
            nx = u.x + dir[i][1];

            if(canVisit(ny,nx) && node[ny][nx].value == 1){
                node[ny][nx].visited = true;
                node[ny][nx].island = u.island;
                q.push(node[ny][nx]);
            }
        }
    }
}

vector<int> minBridge;


void bridge(int island){
    queue<Node> qq;
    // V.visited = true;
    // qq.push(V);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            node[i][j].setVisited();
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(node[i][j].island == island){
                node[i][j].visited = true;
                qq.push(node[i][j]);
            }
        }
    }

    Node U;

    while(!qq.empty()){
        U = qq.front();
        qq.pop();

        // cout << "U " << U.y << " " << U.x << "\n";

        int ny, nx;

        for(int i = 0; i<4; i++){
            ny = U.y + dir[i][0];
            nx = U.x + dir[i][1];

            if (canVisit(ny, nx)){
                if(node[ny][nx].value == 0){
                    node[ny][nx].visited = true;
                    node[ny][nx].dis = U.dis + 1;
                    // cout << "visit " << ny << " " << nx << " " << node[ny][nx].dis << "\n";
                    qq.push(node[ny][nx]);

                }else{
                    if(node[ny][nx].island != island){     // 섬인데 우리땅 아니면
                        node[ny][nx].visited = true;
                        // cout << "min " << ny << " " << nx << " " << U.dis << "\n";
                        minBridge.push_back(U.dis);
                        return;
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int temp;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
        }
    }



    int Cnt = 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if (!node[i][j].visited && node[i][j].value == 1){
                node[i][j].island = Cnt;
                bfs(node[i][j]);
                Cnt++;
            }
        }
    }


    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            node[i][j].setVisited();
        }
    }

    for(int i = 1; i<Cnt; i++){
        bridge(i);
    }



    cout<<*min_element(minBridge.begin(), minBridge.end());
}

