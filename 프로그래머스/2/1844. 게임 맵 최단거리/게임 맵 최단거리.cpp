#include<vector>
#include<iostream>
#include<queue>
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
Node node[101][101];

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return (ny >= 0 && ny<n  && nx>=0 && nx<m && !node[ny][nx].visited && node[ny][nx].value == 1);
}

void bfs(){
    queue<Node> q;
    node[0][0].visited = true;
    node[0][0].cnt = 1;
    q.push(node[0][0]);
    
    Node v;
    int ny, nx;
    
    while(!q.empty()){
        v = q.front();
        q.pop();
        
        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];
            
            if(canVisit(ny, nx)){
                node[ny][nx].visited = true;
                node[ny][nx].cnt = v.cnt+1;
                q.push(node[ny][nx]);
            }
        }
    }
}


int solution(vector<vector<int> > maps)
{
    n = maps.size();
    
    m = maps[0].size();
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            node[i][j].setNode(i, j, maps[i][j]);
        }
    }
    
    bfs();
    
    if(node[n-1][m-1].cnt == 0){
        return -1;
    }
    return node[n-1][m-1].cnt;
}