// 4963
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

class Node{
public:
    int x, y;
    bool visited;
    int land;
    void setNode(int y, int x, int l){
        this->y = y;
        this->x = x;
        land = l;
        visited = false;
    }

    void initNode(){
        land = 0;
        visited = false;
    }
};


int w, h;
Node node[51][51];
int cnt;


bool canVisit(int ny, int nx){
    return (node[ny][nx].land == 1 && !node[ny][nx].visited && ny >= 0 && ny < h && nx >= 0 && nx < w);
}

int dir[8][2] = {
    {-1,0},
    {-1,1},
    {0,1},
    {1,1},
    {1,0},
    {1,-1},
    {0,-1},
    {-1,-1}
};

void bfs(Node& v){
    queue<Node> q;
    v.visited = true;
    q.push(v);

    int ny, nx;

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<8; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];
    
            if(canVisit(ny, nx)){
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


    while(1){
        cin >> w >> h;
        cnt = 0;

        if(w == 0 && h == 0){
            break;
        }


        int temp;
        for(int i = 0; i<h; i++){
            for(int j = 0; j<w; j++){
                cin >> temp;
                node[i][j].setNode(i, j, temp);
            }
        }

        for(int i = 0; i<h; i++){
            for(int j = 0; j<w; j++){
                if(canVisit(i, j)){
                    bfs(node[i][j]);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";


        // 초기화
        for(int i = 0; i<h; i++){
            for(int j = 0; j<h; j++){
                node[i][j].initNode();
            }
        }
    }

}