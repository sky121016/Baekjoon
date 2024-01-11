// 1012
#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int t;
int n, m;
int k;
int cnt;

class Node{
public:
    int x, y;
    bool visited;
    bool plant;
    void setNode(int y, int x){
        this->y = y;
        this->x = x;
        visited = false;
        plant = false;
    }
};

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

Node node[51][51];

bool canVisit(int ny, int nx){
    return (!node[ny][nx].visited && node[ny][nx].plant && ny < n && ny >= 0 && nx < m && nx >= 0);
}

void bfs(Node& v){
    queue<Node> q;
    v.visited = true;
    q.push(v);

    while(!q.empty()){
        v = q.front();
        q.pop();

        int ny, nx;
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

    cin >> t;

    while(t>0){
        cin >> m >> n >> k;
        

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                node[i][j].setNode(i,j);
            }
        }

        int X, Y;
        for(int i = 0; i<k; i++){
            cin >> X >> Y;
            node[Y][X].plant = true;
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(canVisit(i,j)){
                    bfs(node[i][j]);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";

        t--;

        // 초기화
        cnt = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                node[i][j].setNode(i,j);
            }
        }

    }
}


