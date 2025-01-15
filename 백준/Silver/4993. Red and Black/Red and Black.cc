#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

using namespace std;

class Node{
public:
    int y, x;
    bool visited;
    char value;

    void setNode(int y, int x, char v){
        this->y = y;
        this->x = x;
        value = v;
        visited = false;
    }
};

int n, m;
int cnt;
Node node[21][21];
int startY, startX;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return (ny >= 0 && ny < n && nx >= 0 && nx < m && !node[ny][nx].visited && node[ny][nx].value != '#');
}

void bfs(){
    queue<Node> q;
    cnt = 0;

    node[startY][startX].visited = true;
    cnt++;
    q.push(node[startY][startX]);

    Node v;
    while(!q.empty()){
        v = q.front();
        q.pop();

        int ny, nx;
        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)){
                cnt++;
                node[ny][nx].visited = true;
                q.push(node[ny][nx]);
            }
        }
    }

    cout << cnt << "\n";
}


void reset(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            node[i][j].visited = false;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        cin >> m >> n;

        if(n == 0 && m == 0){
            break;
        }

        char temp;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin >> temp;

                if(temp == '@'){
                    startY = i;
                    startX = j;
                }

                node[i][j].setNode(i, j, temp);
            }
        }


        bfs();


        reset();
    }
}
