// 2636
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
public:
    int x, y;
    int cheese;
    bool visited;

    void setNode(int y, int x, int c){
        this->y = y;
        this->x = x;
        cheese = c;
        visited = false;
    }

    void initVisit(){
        visited = false;
    }
};

int w, h;
Node node[101][101];

int hour;
vector<int> cnt;
int totalCheese;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return (!node[ny][nx].visited && ny < h && ny >= 0 && nx < w && nx >= 0);
}

void bfs(Node & v){
    queue<Node> q;
    v.visited = true;
    q.push(v);

    int ny, nx;

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)){
                if(node[ny][nx].cheese == 1){
                    cnt[hour]++;
                    totalCheese--;
                    node[ny][nx].cheese = 0;
                    node[ny][nx].visited = true;
                }else{
                    node[ny][nx].visited = true;
                    q.push(node[ny][nx]);
                }
            }
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;

    int temp;

    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
            if(temp == 1){
                totalCheese++;
            }
        }
    }

    cnt.push_back(0);
    while(totalCheese > 0){
        
        cnt.push_back(0);
        hour++;

        // visited 초기화
        for(int i = 0; i<h; i++){
            for(int j = 0; j<w; j++){
                node[i][j].initVisit();
            }
        }        

        if(canVisit(0,0) && node[0][0].cheese == 0){
            bfs(node[0][0]);
        }

    }

    cout << hour << "\n" << cnt[hour];
}



