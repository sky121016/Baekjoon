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
    int cnt;

    void setNode(int y, int x, char v){
        this->y = y;
        this->x = x;
        value = v;
        visited = false;
        cnt = 0;
    }
};

int n,m;
Node node[3010][3010];
int startY, startX;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};


bool canVisit(int ny, int nx){
    return (ny >= 0 && ny < n && nx >= 0 && nx < m && !node[ny][nx].visited && node[ny][nx].value != '1');
}

int answer;

bool bfs(){
    queue<Node> q;
    node[startY][startX].visited = true;
    q.push(node[startY][startX]);

    int ny, nx;

    Node v;

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)){
                node[ny][nx].visited = true;
                node[ny][nx].cnt = v.cnt + 1;
                if(node[ny][nx].value == '3' || node[ny][nx].value == '4' || node[ny][nx].value == '5'){
                    answer = node[ny][nx].cnt;
                    return true;
                }

                q.push(node[ny][nx]);
            }
        }
    }

    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    char temp;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);

            if(temp == '2'){
                startY = i;
                startX = j;
            }
        }
    }

    if(bfs()){
        cout << "TAK\n"
             << answer;
    }else{
        cout << "NIE";
    }
}
