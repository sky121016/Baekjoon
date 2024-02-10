// 14716
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Node{
public:
    int x, y;
    int value;
    bool visited;
    void setNode(int y, int x, int v){
        this->y = y;
        this->x = x;
        value = v;
        visited = false;
    }
};

int m, n;
Node node[251][251];
int cnt;

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
    return (!node[ny][nx].visited && node[ny][nx].value == 1 && ny >= 0 && ny < m && nx >= 0 && nx < n);
}

void dfs(Node& v){
    v.visited = true;

    int ny, nx;
    for(int i = 0; i<8; i++){
        ny = v.y + dir[i][0];
        nx = v.x + dir[i][1];

        if (canVisit(ny, nx)){
            dfs(node[ny][nx]);
        }
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
            if(node[i][j].value == 1 && !node[i][j].visited){
                dfs(node[i][j]);
                cnt++;
            }
        }
    }

    cout << cnt;
}




