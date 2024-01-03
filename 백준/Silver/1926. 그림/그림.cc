// 1926
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
public:
    int y, x;
    int color;
    bool visited;

    void setNode(int y, int x, int c){
        this->y = y;
        this->x = x;
        color = c;
        visited = false;
    }
};

int n, m;
vector<int> area;
int cnt;
Node node[501][501];

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};


bool canVisit(int ny, int nx){
    return (node[ny][nx].color == 1 && !node[ny][nx].visited && ny >= 0 && ny < n && nx >= 0 && nx < m);
}

void bfs(Node& v){
    queue<Node> q;
    v.visited = true;
    q.push(v);

    area.push_back(1);

    int ny, nx;

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)){
                node[ny][nx].visited = true;
                area[cnt] ++;
                q.push(node[ny][nx]);
            }
        }

    }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int c;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> c;
            node[i][j].setNode(i, j, c);
        }
    }


    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(node[i][j].color == 1 && !node[i][j].visited){
                bfs(node[i][j]);
                
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
    if(area.empty()){
        cout << "0";
    }else{
        cout << *max_element(area.begin(), area.end());
    }
}
