#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node{
public:
    int y, x;
    char value;
    bool visited;

    void setNode(int y, int x, char v){
        this->y = y;
        this->x = x;
        value = v;
        visited = false;
    }

};


int r, c;
Node node[251][251];
int totalSheepCnt;
int totalWolfCnt;

int sCnt;
int wCnt;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return (ny >= 0 && ny < r && nx >= 0 && nx < c && !node[ny][nx].visited && node[ny][nx].value != '#');
}

void bfs(Node& V){
    queue<Node> q;
    V.visited = true;
    q.push(V);

    int ny, nx;
    Node v;

    wCnt = 0;
    sCnt = 0;

    if (V.value == 'v'){
        wCnt++;
    }else if (V.value == 'o'){
        sCnt++;
    }

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)){
                node[ny][nx].visited = true;

                if(node[ny][nx].value == 'v'){
                    wCnt ++;
                }else if(node[ny][nx].value == 'o'){
                    sCnt ++;
                }

                q.push(node[ny][nx]);
            }
        }
    }

    // sheep 이김
    if(wCnt < sCnt){
        totalWolfCnt -= wCnt;
    }else{
        totalSheepCnt -= sCnt;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    char temp;
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);

            if(temp == 'v'){
                totalWolfCnt ++;
            }else if(temp == 'o'){
                totalSheepCnt ++;
            }
        }
    }



    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            if(!node[i][j].visited && node[i][j].value != '#'){
                bfs(node[i][j]);
            }
        }
    }

    cout<<totalSheepCnt<<" "<<totalWolfCnt;
}