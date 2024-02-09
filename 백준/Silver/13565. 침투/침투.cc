// 17086
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Node{
public:
    int x, y;
    char value;
    bool visited;
    void setNode(int y, int x, char v){
        this->y = y;
        this->x = x;
        value = v;
        visited = 0;
    }
};

int m, n;
Node node[1001][1001];
queue<Node> q;
bool canPercolate;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return (!node[ny][nx].visited && node[ny][nx].value == '0' && ny >= 0 && ny < m && nx >= 0 && nx < n);
}


void bfs(){
    Node v;

    while(!q.empty()){
        v = q.front();
        q.pop();

        int ny, nx;
        for (int i = 0; i < 4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if (canVisit(ny, nx)){
                node[ny][nx].visited = true;
                q.push(node[ny][nx]);

                if (ny == m - 1){
                    canPercolate = true;
                    return;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;

    char temp;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);

            if(i == 0 && node[i][j].value == '0'){
                node[i][j].visited = true;
                q.push(node[i][j]);
            }
        }
    }

    bfs();

    if(canPercolate){
        cout<<"YES";
    }else{
        cout << "NO";
    }
}



