// 11053
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Node{
public:
    int y, x;
    bool visited;
    int value;
    bool virus;

    void setNode(int y, int x, int v){
        this->y = y;
        this->x = x;
        value = v;
        visited = false;
        virus = false;
    }
};

int n, m;
Node node[9][9];

int dir[4][2] = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

bool canVisit(int ny, int nx){
    return(ny>=0 && ny<n && nx>=0 && nx<m && node[ny][nx].value == 0 && !node[ny][nx].visited);
}

vector<Node> s;
int Maxarea = 0;
int area;


void reset(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            node[i][j].visited = false;
            node[i][j].virus = false;
        }
    }
}

void bfs(Node& V){
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

            if(canVisit(ny, nx)){
                node[ny][nx].visited = true;
                node[ny][nx].virus = true;
                q.push(node[ny][nx]);
            }
        }
    }

}

void count(){
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         cout<<node[i][j].value<<" ";
    //     }
    //     cout<<"\n";
    // }
    area = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(node[i][j].value == 0 && !node[i][j].virus){ // 영역 구하기
                area++;
            }
        }
    }


}

void spread(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!node[i][j].visited && node[i][j].value == 2){ // 확산
                bfs(node[i][j]);
            }
        }
    }

}


void dfs(int x, int cnt){
    if(cnt == 3){
        spread();
        count();
        if(area>Maxarea){
            Maxarea = area;
        }

        reset();
    }else{
        for(int i = x+1; i<n*m; i++){
            int r = i/m;
            int c = i%m;
            if(node[r][c].value == 0){   
                node[r][c].value = 1;
                dfs(i, cnt+1);
                node[r][c].value = 0;
            }
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // 3개 될때까지 어디다 세울지 골라. dfs
    // 3개 됐으면 bfs로 확산시켜.
    // 안전영역 구해.
    // 최대 안전 영역보다 크면 갱신시켜

    cin >> n >> m;
    int temp;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
        }
    }

    for(int i = 0; i<n*m; i++){
        int r = i/m;
        int c = i%m;
        if(node[r][c].value == 0){
            node[r][c].value = 1;
            dfs(i, 1);
            node[r][c].value = 0;
        }
    }


    cout<<Maxarea;


}
