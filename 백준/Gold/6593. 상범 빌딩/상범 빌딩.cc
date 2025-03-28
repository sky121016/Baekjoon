#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

using namespace std;

class Node{
public:
    int y, x, z;
    bool visited;
    char value;
    int cnt;

    void setNode(int y, int x, int z, char v){
        this->y = y;
        this->x = x;
        this->z = z;
        value = v;
        visited = false;
        cnt = 0;
    }
};

int dir[6][3] = {
    {-1, 0, 0},
    {0, 1, 0},
    {1, 0, 0},
    {0, -1, 0},
    {0, 0, 1},
    {0, 0, -1},
};


int l, r, c;
Node node[31][31][31];
int start[3];
int ans;

void reset(){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < r; j++){
            for(int k = 0; k < c; k++){
                node[j][k][i].cnt = 0;
                node[j][k][i].visited = true;
            }
        }
    }
    ans = 0;
}

bool canVisit(int ny, int nx, int nz){
    return (ny >= 0 && ny < r && nx >= 0 && nx < c && nz >= 0 && nz < l && !node[ny][nx][nz].visited && node[ny][nx][nz].value != '#');
}



bool bfs(){
    queue<Node> q;
    node[start[0]][start[1]][start[2]].visited = true;
    q.push(node[start[0]][start[1]][start[2]]);

    int ny, nx, nz;

    Node v;
    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<6; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];
            nz = v.z + dir[i][2];

            if(canVisit(ny, nx, nz)){
                node[ny][nx][nz].visited = true;
                node[ny][nx][nz].cnt = v.cnt + 1;
                q.push(node[ny][nx][nz]);

                if(node[ny][nx][nz].value == 'E'){
                    ans = node[ny][nx][nz].cnt;
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        cin >> l >> r >> c;

        if (l == 0 && r == 0 && c == 0){
            break;
        }

        char temp;

        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    cin >> temp;
                    node[j][k][i].setNode(j, k, i, temp);
                    if(temp == 'S'){
                        start[0] = j;
                        start[1] = k;
                        start[2] = i;
                    }
                }
            }
        }

        if(bfs()){
            cout << "Escaped in " << ans << " minute(s).\n";
        }else{
            cout << "Trapped!\n";
        }

        reset();
    }


}