// 13398
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdlib>
using namespace std;


class Node{
public:
    int y, x;
    int value;
    bool visited;

    void setNode(int y, int x, int v){
        this->y = y;
        this->x = x;
        value = v;
        visited = false;
    }
};

Node node[101][71];
int n, m;
int cnt;

bool canVisit(int ny, int nx){
    return (ny >= 0 && ny < n && nx >= 0 && nx < m);
}

int dir[8][2] ={
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1},
    {-1, -1},
};  

void bfs(Node& V){
    queue<Node> q;

    V.visited = true;
    q.push(V);

    Node v;
    int ny, nx;

    bool highest = true;



    while(!q.empty()){
        v = q.front();
        q.pop();


        for(int i = 0; i<8; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)){
                if(v.value == node[ny][nx].value && !node[ny][nx].visited){
                    node[ny][nx].visited = true;
                    q.push(node[ny][nx]);
                }else if(node[ny][nx].value > v.value){
                    highest = false;
                }
            }
        }
    

    }

    if(highest){
        cnt++;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int temp;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
        }
    }

    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!node[i][j].visited){
                bfs(node[i][j]);
            }
        }
    }

    cout << cnt;
}


