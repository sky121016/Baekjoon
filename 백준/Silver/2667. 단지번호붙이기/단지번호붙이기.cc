// 2667 단지 번호 붙이기
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;



class Node{
public:
    int x,y;
    bool visited;
    char home;
    void setNode(int y, int x){
        this->y = y;
        this->x = x;
        visited = false;
    }
};


Node node[25][25];
int group[625];
int n;

int dir[4][2] = {
    {-1,0},
    {0,1},
    {1,0},
    {0,-1},
};


bool canVisit(int ny, int nx){
    return (!node[ny][nx].visited && node[ny][nx].home == '1' && nx > -1 && nx < n && ny > -1 && ny < n);
}



void bfs(Node& v, int k){
    queue<Node> q;
    q.push(v);
    v.visited = true;

    group[k] = 1;

    int nx, ny;

    while(!q.empty()){
        v = q.front();
        q.pop();
        for(int i = 0; i<4; i++){
            ny = v.y+dir[i][0];
            nx = v.x+dir[i][1];

            if(canVisit(ny, nx)){
                node[ny][nx].visited = true;
                q.push(node[ny][nx]);
                group[k]++;
            }
        }
    }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin>>n;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            node[i][j].setNode(i, j);
            cin >> node[i][j].home;
        }
    }

    int k = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(!node[i][j].visited && node[i][j].home == '1'){
                bfs(node[i][j], k);
                k++;
            }
        }
    }


    sort(group, group + k);

    cout << k << "\n";

    for(int i = 0; i<k; i++){
        cout<<group[i]<<"\n";
    }

}
