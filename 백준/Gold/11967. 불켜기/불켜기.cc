
// 13398
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdlib>
using namespace std;

int n;
int m;

bool light[110][110];
bool visited[110][110];

int cnt;

vector<pair<int, int> > map[110][110];

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

queue<pair<int, int> > q;


bool checkArea(int ny, int nx){
    return (ny > 0 && ny <= n && nx > 0 && nx <= n);
}


// 주변이 visit 가능 -> ny, nx 까지도 길이 있음
bool canVisit(int ny, int nx){
    for(int i = 0;  i<4; i++){
        int nny = ny + dir[i][0];
        int nnx = nx + dir[i][1];

        if(checkArea(nny, nnx) && visited[nny][nnx]){
            return true;
        }
    }


    return false;
}



void visit(){
    q.push(make_pair(1, 1));

    int ny, nx, y, x;
    int dis;

    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int i = 0; i<map[y][x].size(); i++){
            ny = map[y][x][i].first;
            nx = map[y][x][i].second;

            if(!light[ny][nx]){
                light[ny][nx] = true;
                cnt++;
            }

            if(!visited[ny][nx] && canVisit(ny, nx)){
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }

        }

        for(int i = 0; i<4; i++){
            ny = y + dir[i][0];
            nx = x + dir[i][1];

            // 불은 켜져있는데 !visited인 곳 방문 가능으로 만들기
            if(checkArea(ny, nx)&&!visited[ny][nx] && light[ny][nx]){
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }


    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int x, y, a, b;

    cin >> n >> m;
    int dis = 0;

    for(int i = 0; i<m; i++){
        cin >> x >> y >> a >> b;
        map[y][x].push_back((make_pair(b, a)));
    }

    light[1][1] = true;
    visited[1][1] = true;
    cnt++;

    visit();

    cout << cnt;
}



