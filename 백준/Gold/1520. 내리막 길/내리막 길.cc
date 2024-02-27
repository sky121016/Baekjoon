// 1520
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

class Node{
public:
    int y, x;
    // bool visited;
    int value;
    void setNode(int y, int x, int v)
    {
        this->y = y;
        this->x = x;
        value = v;
        // visited = false;
    }
};


int m, n;
Node node[501][501];
int cnt;
int dp[501][501];

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return (ny >= 0 && ny < m && nx >= 0 && nx < n);
}

int dfs(Node & v){
    if(dp[v.y][v.x] != -1){
        return dp[v.y][v.x];
    }
    if(v.y == m-1 && v.x == n-1){
        return 1;
    }else{
        int ny, nx;

        dp[v.y][v.x] = 0;
        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if (canVisit(ny, nx) && v.value > node[ny][nx].value){
                dp[v.y][v.x] += dfs(node[ny][nx]);
            }
        }
        return dp[v.y][v.x];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;

    int temp;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
        }
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            dp[i][j] = -1;
        }
    }

    dfs(node[0][0]);

 
    cout << dp[0][0];
}