// 3187
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
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
        visited = 0;
    }
};

int R,C;
int vTotal;
int kTotal;

int areaCnt;
vector<int> vCnt;
vector<int> kCnt;

Node node[251][251];


int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return (ny >= 0 && ny < R && nx >= 0 && nx < C && !node[ny][nx].visited && node[ny][nx].value != '#');
}

void bfs(Node& V){
    queue<Node> q;
    V.visited = true;
    q.push(V);

    Node v;
    int ny, nx;

    while(!q.empty()){
        v = q.front();
        q.pop();

        if(v.value == 'v'){
            vCnt[areaCnt]++;
        }else if (v.value == 'k'){
            kCnt[areaCnt]++;
        }

        for(int i = 0; i<4; i++){
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

    cin >> R >> C;

    char temp;
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);

            // count # of v and k
            if(temp == 'v'){
                vTotal ++;
            }else if(temp == 'k'){
                kTotal ++;
            }
        }
    }

    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            if(!node[i][j].visited && node[i][j].value != '#'){
                vCnt.push_back(0);
                kCnt.push_back(0);
                bfs(node[i][j]);
                areaCnt++;
            }
        }
    }


    for(int i = 0; i<areaCnt; i++){
        if(vCnt[i] > 0 && kCnt[i] > 0){

            if(vCnt[i] < kCnt[i]){
                vTotal -= vCnt[i];
            }else{
                kTotal -= kCnt[i];
            }
        }
    }

    cout << kTotal << " " << vTotal;
}

