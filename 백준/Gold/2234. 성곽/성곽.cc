// 2234
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int m, n;
int roomCnt;
int sizeCnt;
vector<int> sizes;
vector<int> breakWallRoomSizes;



class Node{
public:
    int y, x;
    int roomNum;
    int wall[4];         // W, N, E, S
    bool visited;
    
    void setNode(int y, int x, int v){
        this -> y = y;
        this -> x = x;

        int i = 0;
        while(v > 1){
            if (v % 2 == 1){
                wall[3-i] = 1;
            }else{
                wall[3-i] = 0;
            }
            i++;
            v /= 2;
        }
        if(v>=1){
            wall[3-i] = 1;
        }
    }
};

Node map[51][51];

int dir[4][2] = {
    {0, -1},
    {-1, 0},
    {0, 1},
    {1, 0},
};

bool canVisit(int ny, int nx){
    return (!map[ny][nx].visited && ny <= m && ny > 0 && nx <= n && nx > 0);
}

void bfs(Node& V){
    queue<Node> q;

    roomCnt++;
    q.push(V);
    V.visited = true;
    V.roomNum = roomCnt;
    sizeCnt++;

    Node v;

    while(!q.empty()){
        v = q.front();
        q.pop();

        int ny, nx;
        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];
            

            if(v.wall[3-i] == 0 && canVisit(ny, nx)){         // 벽 없고 방문할수 있으면
                q.push(map[ny][nx]);
                map[ny][nx].visited = true;
                map[ny][nx].roomNum = roomCnt;
                sizeCnt++;
            }
        }
    }


    // save size
    sizes.push_back(sizeCnt);
    sizeCnt = 0;

    while(!q.empty()){
        q.pop();
    }

}


void breakWall(){
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            int ny, nx;
            int temp;
            
            for(int k = 0; k<4; k++){
                ny = map[i][j].y + dir[k][0];
                nx = map[i][j].x + dir[k][1];

                if (map[i][j].wall[3 - k] == 1 && map[i][j].roomNum != map[ny][nx].roomNum && ny <= m && ny > 0 && nx <= n && nx > 0){
                    temp = sizes[map[i][j].roomNum - 1] + sizes[map[ny][nx].roomNum - 1];
                    breakWallRoomSizes.push_back(temp);
                }

            }

        }
    }



}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int value;
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            cin >> value;
            map[i][j].setNode(i, j, value);
        }
    }




    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(!map[i][j].visited){
                bfs(map[i][j]);
            }
        }
    }

    breakWall();

    cout << roomCnt<<"\n";
    cout << *max_element(sizes.begin(), sizes.end())<<"\n";
    cout << *max_element(breakWallRoomSizes.begin(), breakWallRoomSizes.end())<<"\n";
}
