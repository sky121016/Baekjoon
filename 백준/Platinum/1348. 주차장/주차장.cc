// 1348
#include<iostream>
#include<vector>
#include<stack>
#include <cstring>
#include<queue>
#include<algorithm>

using namespace std;


class Node{
public:
    int y, x;
    char value;
    bool visited;
    int cnt;
    int carNum;
    int parkNum;

    void setNode(int y, int x, char v){
        this->y = y;
        this->x = x;
        value = v;
        visited = false;
    }

    void setCarNum(int i){
        carNum = i;
    }

    void setParkNum(int i){
        parkNum = i;
    }
};


int r, c;
int dist[101][101];
vector<int> park[101];
Node node[101][101];
int carCnt;
int parkCnt;
vector<pair<int, int> > carLoc;
vector<pair<int, int> > parkLoc;
int low, high, m;
int inf = 99999999;

int answer = -1;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};


bool canVisit(int ny, int nx){
    return !node[ny][nx].visited && ny >= 0 && ny < r && nx >= 0 && nx < c && node[ny][nx].value != 'X';
}

void bfs(Node& V){
    queue<Node> q;

    V.visited = true;
    V.cnt = 0;
    q.push(V);


    Node v;
    while(!q.empty()){
        v = q.front();
        q.pop();
        int ny, nx;
        for(int i= 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)){
                node[ny][nx].visited = true;
                node[ny][nx].cnt = v.cnt+1;
                q.push(node[ny][nx]);

                // if(node[ny][nx].value == 'P'){
                //     dist[V.carNum][node[ny][nx].parkNum] = node[ny][nx].cnt;
                //     park[V.carNum].push_back(node[ny][nx].parkNum);
                // }
            }
        }
    }


    for(int i = 0; i<parkCnt; i++){
        if(node[parkLoc[i].first][parkLoc[i].second].cnt > 0){
            park[V.carNum].push_back(i);        // 주차장 번호 넣기
            dist[V.carNum][i] = node[parkLoc[i].first][parkLoc[i].second].cnt;  // 차번호 -> 주차장 번호 거리
        }
    }
}


void resetVisited(){
    for(int i = 0; i< r; i++){
        for(int j = 0; j<c; j++){
            node[i][j].visited = false;
            node[i][j].cnt = 0;
        }
    }
}

bool cVisited[101];
int pMatch[101];

bool dfs(int car, int mid){
    if(cVisited[car]){
        return false;
    }

    cVisited[car] = true;

    for(int i = 0; i<park[car].size(); i++){
        if(mid >= dist[car][park[car][i]]){
            // if(dist[car][i] > 0){
                if(pMatch[park[car][i]] == -1){
                    pMatch[park[car][i]] = car;
                    return true;
                }else if(dfs(pMatch[park[car][i]], mid)){
                    pMatch[park[car][i]] = car;
                    return true;
                    
                }
            // }

        }
    }

    return false;
}

int match(int mid){
    int ans = 0;

    // 초기화

    for(int i = 0; i<carCnt; i++){
        memset(cVisited, false, sizeof cVisited);
        if(dfs(i, mid)){
            ans ++;
        }
    }

    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    char temp;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> temp;

            node[i][j].setNode(i, j, temp);

            if(temp == 'C'){
                carLoc.push_back(make_pair(i,j));
                node[i][j].setCarNum(carCnt);
                carCnt ++;
            }else if(temp == 'P'){
                parkLoc.push_back(make_pair(i,j));
                node[i][j].setParkNum(parkCnt);
                parkCnt ++;
            }


            dist[i][j] = inf;
        }
    }

    // bfs 돌려서 c-p 최단 거리 구해놓기
    for(int i = 0; i<carCnt; i++){
        int cy = carLoc[i].first;
        int cx = carLoc[i].second;

        bfs(node[cy][cx]);

        resetVisited();
    }


    low = 0;
    high = 2500;
    

    while(low<=high){
        m = (low + high) / 2;
        
        memset(pMatch, -1, sizeof pMatch);

        int result = match(m);

        if(carCnt==result){
            answer = m;
            high = m-1;
        }else{
            low = m+1;
        }
    }
    
    cout<<answer<<"\n";
    

}




