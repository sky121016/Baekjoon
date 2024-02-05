// 7569
#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

class Node{
public:
    int x, y, z;
    int tomato;
    bool visited;
    int day;
    void setNode(int z, int y, int x, int t){
        this->z = z;
        this->y = y;
        this->x = x;
        tomato = t;
        visited = false;
        day = 0;
    }
};


int m, n, h;
Node node[101][101][101];       // H N M
int ans;
int totalAmount;
queue<Node> q;

int dir[6][3] = {
    {-1, 0, 0},
    {0, -1, 0},
    {0, 0, 1},
    {0, 1, 0},
    {0, 0, -1},
    {1, 0, 0}
};

bool canVisit(int z, int y, int x){
    return (z < h && z >= 0 && y < n && y >= 0 && x < m && x >= 0 && !node[z][y][x].visited && node[z][y][x].tomato ==0);
}

void bfs(){
    Node v;

    while(!q.empty()){
        v = q.front();

        node[v.z][v.y][v.x].visited = true;
        q.pop();

        int nz, ny, nx;
        for(int i = 0; i<6; i++){
            nz = v.z + dir[i][0];
            ny = v.y + dir[i][1];
            nx = v.x + dir[i][2];


            if(canVisit(nz, ny, nx)){

                node[nz][ny][nx].visited = true;
                node[nz][ny][nx].day = v.day + 1;
                node[nz][ny][nx].tomato = 1;
                q.push(node[nz][ny][nx]);
                totalAmount--;

                if(ans < node[nz][ny][nx].day){
                    ans = node[nz][ny][nx].day;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> h;

    int temp;

    for(int i = 0; i<h; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<m; k++){
                cin >> temp;
                node[i][j][k].setNode(i, j, k, temp);
                if(temp == 1){
                    q.push(node[i][j][k]);
                }
                if(temp == 0){
                    totalAmount++;
                }
            }
        }
    }

    bfs();


    if(totalAmount>0){
        cout << "-1";
    }else{
        cout << ans;
    }
    

}