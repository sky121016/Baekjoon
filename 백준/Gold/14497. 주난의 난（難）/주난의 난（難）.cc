#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
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
    bool jump;
    
    void setNode(int y, int x, char v){
        this->y = y;
        this->x = x;
        value = v;
        visited = false;
        jump = false;
    }

};

int n, m;
int x1;

int x2, y2;
int yy1;
int cnt;

Node node[301][301];

int dir[4][2]= {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return (ny>0 && ny<=n && nx>0 && nx<=m && !node[ny][nx].visited);
}

bool found;

void bfs(){
    queue<Node> q;
    node[x1][yy1].visited = true;
    q.push(node[x1][yy1]);

    Node v;
    while(!q.empty() && !found){
        v = q.front();
        q.pop();

        int ny, nx;

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)){
                node[ny][nx].visited = true;

                if(node[ny][nx].value == '1'){
                    node[ny][nx].jump = true;
                }else if(node[ny][nx].value == '0'){
                    q.push(node[ny][nx]);
                }else if(node[ny][nx].value == '#'){
                    found = true;
                    break;
                }
            }
        }


    }
}


void reset(){
     for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(node[i][j].jump){
                node[i][j].value = '0';
                node[i][j].jump = false;
            }
            node[i][j].visited = false;
            
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> x1;
    cin >> yy1;
    cin >> x2 >> y2;

    char temp;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
        }
    }

    while(true){
        bfs();
        cnt++;
        if(found){
            break;
        }


        reset();
    }

    cout << cnt;
}
