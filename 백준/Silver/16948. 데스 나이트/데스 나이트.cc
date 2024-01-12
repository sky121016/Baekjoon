// 16948
#include<iostream>
#include<queue>
#include<vector>
using namespace std;


class Node{
public:
    int x, y;
    bool visited;
    int dis;
    void setNode(int y, int x){
        this->y = y;
        this->x = x;
        dis = 0;
        visited = false;
    }
};

int dir[6][2] = {
    {-2, 0},
    {-1, 2},
    {1, 2},
    {2, 0},
    {1, -2},
    {-1, -2},
};

int n;
int r1, c1;
int r2, c2;
Node node[201][201];

bool canVisit(int ny, int nx){
    return (!node[ny][nx].visited && ny < n && ny >= 0 && nx < n && nx >= 0);
}

int bfs(Node& v){
    queue<Node> q;

    v.visited = true;
    q.push(v);

    int ny, nx;

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<6; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)){
                
                node[ny][nx].visited = true;
                node[ny][nx].dis = v.dis + 1;
                
                if(ny == c2 && nx == r2){
                    return node[ny][nx].dis;
                }

                q.push(node[ny][nx]);
            }
        }
    }

    return -1;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;


    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            node[i][j].setNode(i, j);
        }
    }

    cout << bfs(node[c1][r1]);
}
