// 4485
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

class Node{
public:
    int y, x;
    int cost;

    void setNode(int y, int x, int cost){
        this->y = y;
        this->x = x;
        this->cost = cost;
    }
};

int n;
int inf = 999999999;
int cnt;

Node node[126][126];
int dist[126][126];
int dir[4][2]={
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};


bool canVisit(int ny, int nx){
    return ny >= 0 && ny < n && nx >= 0 && nx < n;
}

void shortest(){
    queue<Node> q;

    dist[0][0] = node[0][0].cost;
    q.push(node[0][0]);

    Node v;
    while(!q.empty()){
        v = q.front();
        q.pop();

        int ny, nx;
        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx) && dist[ny][nx] > dist[v.y][v.x] + node[ny][nx].cost){
                dist[ny][nx] = dist[v.y][v.x] + node[ny][nx].cost;
                q.push(node[ny][nx]);
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    n = -1;

    int k;
    cin >> n;
    while(n != 0){
        
        cnt++;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                dist[i][j] = inf;
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cin >> k;
                node[i][j].setNode(i, j, k);
            }
        }

        shortest();

        cout << "Problem " << cnt << ": " << dist[n - 1][n - 1] << "\n";

        cin >> n;
    }


}