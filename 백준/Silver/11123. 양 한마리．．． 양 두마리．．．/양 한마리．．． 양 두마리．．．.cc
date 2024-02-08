// 17086
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Node{
public:
    int x, y;
    bool isSheep;
    bool visited;
    void setNode(int y, int x, char c){
        this->y = y;
        this->x = x;
        if(c == '#'){
            isSheep = true;
        }else{
            isSheep = false;
        }
        visited = false;
    }
};

int t;
int h, w;
Node node[101][101];
int cnt;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return (!node[ny][nx].visited && node[ny][nx].isSheep && ny >= 0 && ny < h && nx >= 0 && nx < w);
}

queue<Node> q;
void bfs(Node& v){
    v.visited = true;
    q.push(v);

    while(!q.empty()){
        v = q.front();
        q.pop();

        int ny, nx;
        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if (canVisit(ny, nx)){
                node[ny][nx].visited = true;
                q.push(node[ny][nx]);
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    char temp;

    while(t > 0){
        cin >> h >> w;
        for(int i = 0; i<h; i++){
            for(int j = 0; j<w; j++){
                cin >> temp;
                node[i][j].setNode(i, j, temp);
            }
        }

        for(int i = 0; i<h; i++){
            for(int j = 0; j<w; j++){
                if(node[i][j].isSheep && !node[i][j].visited){
                    bfs(node[i][j]);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";

        cnt = 0;
        while(!q.empty()){
            q.pop();
        }

        t--;
    }
}
