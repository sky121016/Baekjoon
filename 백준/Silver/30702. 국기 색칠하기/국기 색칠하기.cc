// 30702
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;


class Node{
public:
    int y, x;
    bool visited;
    char value;

    void setNode(int y, int x, char v){
        this->y = y;
        this->x = x;
        visited = false;
        value = v;
    }
};

int n, m;
Node node[51][51];
Node flag[51][51];

int dir[4][2] = {
    {-1,0},
    {0, 1},
    {1,0},
    {0,-1},
};

bool canVisit(int ny, int nx){
    return(ny>=0 && ny<n && nx>=0 && nx<m);
}

void bfs1(Node& V){
    queue<Node> q;

    V.visited = true;
    q.push(V);

    Node v;
    int ny, nx;

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx) && !node[ny][nx].visited && node[ny][nx].value == v.value){
                node[ny][nx].visited = true;
                q.push(node[ny][nx]);
            }
        }
    }
}

void bfs2(Node& V){
    queue<Node> q;

    V.visited = true;
    q.push(V);

    Node v;
    int ny, nx;

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)&& !flag[ny][nx].visited && flag[ny][nx].value == v.value){
                flag[ny][nx].visited = true;
                q.push(flag[ny][nx]);
            }
        }
    }
}

bool compare(int y, int x){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(node[i][j].visited){
                if(!flag[i][j].visited){
                    return false;
                }
            }
        }
    }
    return true;
}

void reset(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            node[i][j].visited = false;
            flag[i][j].visited = false;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    char temp;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> temp;
            flag[i][j].setNode(i, j, temp);
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            reset();
            if(!node[i][j].visited){
                bfs1(node[i][j]);
                bfs2(flag[i][j]);


                if(!compare(i, j)){
                    cout << "NO";
                    return 0;
                }
            }
        }
    }


    
    cout<<"YES";

    return 0;
}

