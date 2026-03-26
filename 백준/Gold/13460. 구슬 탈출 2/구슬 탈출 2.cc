// 11053
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;

class State{
public:
    int ry;
    int rx;
    int by;
    int bx;
    int cnt;

    void setNode(int ry, int rx, int by, int bx, int cnt){
        this->ry = ry;
        this->rx = rx;
        this->by = by;
        this->bx = bx;
        this->cnt = cnt;
    }
};

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

int endY, endX;
char map[11][11];

bool canVisit(int ny, int nx){
    return (ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] != '#');
}

queue<State> q;
int nry, nrx;
int nby, nbx;
int cnt[2];
bool isGoal[2];

void move(int* ny, int* nx, int y, int x, int dy, int dx, int idx){
    *ny = y;
    *nx = x;
    cnt[idx] = 0;
    while(canVisit(*ny + dy, *nx + dx) && map[*ny][*nx] != '#'){
        *ny = *ny + dy;
        *nx = *nx + dx;
        cnt[idx]++;
        if(map[*ny][*nx] == 'O'){
            // cout<<"goal!"<<idx<<"\n";
            isGoal[idx] = true;
            break;
        }
    }
}
bool visited[11][11][11][11];

void bfs(){

    while(!q.empty()){
        State s;
        s = q.front();
        q.pop();

        if(s.cnt >= 10){
            continue;
        }

        int ry = s.ry;
        int rx = s.rx;
        int by = s.by;
        int bx = s.bx;

        for(int i = 0; i<4; i++){
            isGoal[0] = false;
            isGoal[1] = false;
            
            move(&nry, &nrx, ry, rx, dir[i][0], dir[i][1], 0);
            move(&nby, &nbx, by, bx, dir[i][0], dir[i][1], 1);


            if(isGoal[1]){
                continue;
            }else if(isGoal[0]){
                cout<<s.cnt+1;
                return;
            }

            if(nry == nby && nrx == nbx){
                if(cnt[0] > cnt[1]){
                    nry -= dir[i][0];
                    nrx -= dir[i][1];
                }else{
                    nby -= dir[i][0];
                    nbx -= dir[i][1];
                }
            }


            
            // cout<<"r "<<nry<<" "<<nrx<<'\n';
            // cout<<"b "<<nby<<" "<<nbx<<'\n';

            if(!visited[nry][nrx][nby][nbx]){
                visited[nry][nrx][nby][nbx] = true;
                State ns;
                ns.setNode(nry, nrx, nby, nbx, s.cnt+1);
                q.push(ns);
            }
            
        }
    }

    cout<<"-1";
  
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    char temp;
    int ry, rx;
    int by, bx;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>temp;
            map[i][j] = temp;
            if(temp == 'R'){
                ry = i;
                rx = j;
            }else if(temp == 'B'){
                by = i;
                bx = j;
            }else if(temp == 'O'){
                endY = i;
                endX = j;
            }
        }
    }


    State ns;
    ns.setNode(ry, rx, by, bx, 0);
    q.push(ns);


    bfs();


}
