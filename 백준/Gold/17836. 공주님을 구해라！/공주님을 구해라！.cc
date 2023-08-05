// 17836 공주님
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Map{
public:
    int x, y;
    bool visited[2];
    int value;
    bool gram;
    int cnt;

    void setMap(int y, int x, int value){
        this->x = x;
        this->y = y;
        this->value = value;
        visited[0] = false;         // 검 없을 때
        visited[1] = false;         // 검 있을 때
        gram = false;
        cnt = 0;
    }
};

int N, M;
int T;
Map map[101][101];


int dir[12][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};


bool canVisit(int ny, int nx, bool gram){
    if(gram == true){          // 검을 얻었으면 벽 상관 x
        return (!map[ny][nx].visited[1] && nx >= 0 && nx < M && ny >= 0 && ny < N);
    }else{
        return (!map[ny][nx].visited[0] && map[ny][nx].value != 1 && nx >= 0 && nx < M && ny >= 0 && ny < N);
    }
}

int bfs(){
    queue<Map> q;
    q.push(map[0][0]);
    map[0][0].visited[0] = true;
    map[0][0].visited[1] = true;


    Map v;
    int ny, nx;

    while(!q.empty()){
        v = q.front();
        q.pop();

        if(v.x == M-1 && v.y == N-1){return v.cnt;}

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx, v.gram)){
                if(v.gram == true){
                    map[ny][nx].visited[1] = true;
                }else{
                    map[ny][nx].visited[0] = true;
                }

                map[ny][nx].cnt = v.cnt + 1;

                if(map[ny][nx].value == 2){         // 검 획득
                    map[ny][nx].gram = true;
                }else{
                    map[ny][nx].gram = v.gram;
                }

                q.push(map[ny][nx]);
            }
        }
    }

    return -1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> T;


    int v;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> v;
            map[i][j].setMap(i, j, v);
        }
    }


    int ans;
    ans = bfs();
    if(ans <= T && ans > -1){
        cout<<ans;
    }else{
        cout<<"Fail";
    }

}

