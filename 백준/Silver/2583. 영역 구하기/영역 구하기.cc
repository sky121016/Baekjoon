// 2583
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include <climits>

using namespace std;

class Node{
public:
    int y, x;
    bool visited;

    void setNode(int y, int x){
        this->y = y;
        this->x = x;
    }
};

int n, m;
int k;
Node node[101][101];
int groupCnt;
int groupSize;
vector<int> area;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return ny>=0 && ny<m && nx>=0 && nx<n && !node[ny][nx].visited;
}

void bfs(Node& V){
    queue<Node> q;
    V.visited = true;
    q.push(V);

    Node v;
    int ny, nx;
    groupSize = 1;


    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)){
                node[ny][nx].visited = true;
                groupSize++;
                q.push(node[ny][nx]);
            }
        }

    }

    area.push_back(groupSize);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> k;

    int x1, y1, x2, y2;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            node[i][j].setNode(i,j);
        }
    }


    for(int i = 0; i<k; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = y1; i<y2; i++){
            for(int j = x1; j<x2; j++){
                node[i][j].visited = true;
            }

        }
    }

    for (int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(!node[i][j].visited){
                groupCnt++;
                bfs(node[i][j]);
            }
        }
    }

    sort(area.begin(), area.end());

    cout << groupCnt << "\n";

    for (int i = 0; i < area.size(); i++){
        cout << area[i] << " ";
    }
}
