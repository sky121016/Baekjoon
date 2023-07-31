
// 14442 벽2
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


class Node{
public:
    int x,y;
    int broken;

    void setNode(int y, int x){
        this->y = y;
        this->x = x;
        broken = 0;
    }
};

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

int visited[11][1001][1001];
char map[1001][1001];
Node node[1001][1001];

int n, m, k;

bool canVisit(int ny, int nx){
    return (nx >= 0 && nx < m && ny >= 0 && ny < n);
}


int bfs(){
    queue<Node> q;

    for(int i = 0 ; i<=k; i++){
        visited[i][0][0] = 1;            // 시작점 방문처리
    }

    q.push(node[0][0]);

    Node v;
    int ny, nx;

    while(!q.empty()){
        v = q.front();
        int broken = v.broken;
        q.pop();

        if(v.y == n-1 && v.x == m-1){
            return visited[broken][n-1][m-1];        // 답 출력
        }


        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];
            

            if(!canVisit(ny, nx)){continue;}            

            if(map[ny][nx] == '0' && visited[broken][ny][nx] < 1){         // 벽 X. visited X
                visited[broken][ny][nx] = visited[broken][v.y][v.x] + 1;         // 거리
                node[ny][nx].broken = broken;
                q.push(node[ny][nx]);

            }else if(map[ny][nx] == '1' && broken < k && visited[broken+1][ny][nx]<1){    // 벽 O. 부수기 가능. visited X
                visited[broken+1][ny][nx] = visited[broken][v.y][v.x] + 1;
                node[ny][nx].broken = broken + 1;
                q.push(node[ny][nx]);
            }
        }
    }

    return -1;
    
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> m >> k;



    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
            node[i][j].setNode(i, j);
        }
    }

    cout << bfs();

}


