// 2357

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;


class Node{
public:
    int y, x;
    bool visited;
    int value;
    int cnt;

    void setNode(int y, int x, int v){
        this->y = y;
        this->x = x;
        value = v;
        visited = false;
        cnt = 0;
    }
};

int n, m;
vector<Node> virus;
Node node[51][51];
queue<Node> q;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return (!node[ny][nx].visited && node[ny][nx].value != 1 && ny >= 0 && ny < n && nx >= 0 && nx < n);
}


int maxTime;

vector<int> times;

void reset(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            node[i][j].visited = false;
            node[i][j].cnt = 0;
        }
    }

    while(!q.empty()){
        q.pop();
    }
}

void bfs(){
    Node v;

    int ny, nx;

    maxTime = 0;

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)){
                node[ny][nx].visited = true;
                node[ny][nx].cnt = v.cnt + 1;
                q.push(node[ny][nx]);
                
                if(node[ny][nx].value == 2){
                    node[ny][nx].cnt = 0;
                }

                if(node[ny][nx].cnt > maxTime){
                    maxTime = node[ny][nx].cnt;
                }
            }
        }
    }


    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(!node[i][j].visited && node[i][j].value == 0){
                maxTime = 2501;
            }
        }
    }

    times.push_back(maxTime);
}

bool selected[2501];

void pushVirus(){
    for(int i = 0; i<virus.size(); i++){
        if(selected[i]){
            node[virus[i].y][virus[i].x].visited = true;
            q.push(virus[i]);
        }
    }
}


void selectVirus(int cnt, int idx){
    if(cnt == m){
        pushVirus();
        bfs();
        reset();
    }

    for(int i = idx; i<virus.size(); i++){
        selected[i] = true;
        selectVirus(cnt+1, i+1);
        selected[i] = false;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int temp;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);

            if(temp == 2){
                virus.push_back(node[i][j]);
            }
        }
    }

    selectVirus(0, 0);


    int ans = *min_element(times.begin(), times.end());

    if(ans == 2501){
        cout << -1;
    }else{
        cout << ans;
    }
}

