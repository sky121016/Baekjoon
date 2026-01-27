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
    bool fireVisited;
    char value;
    int dis;
    int fireDis;

    void setNode(int y, int x, char v){
        this->y = y;
        this->x = x;
        value = v;
        visited = false;
        fireVisited = false;
        dis = 0;
        fireDis = 0;
    }
};

int t;
int c, r;
queue<Node> qfire;
queue<Node> q;

Node node[1002][1002];



bool isPossible = false;
void reset(){
    while(!q.empty()){
        q.pop();
    }
    isPossible = false;

}

int dir[4][2] = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

bool canVisit(int ny, int nx){
    return(ny>0 && ny<=r && nx>0 && nx<=c && node[ny][nx].value != '#');
}

bool isEscaped(int ny, int nx){
    return(ny == 1 || ny == r || nx == 1 || nx == c);
}



void bfs(){
    int ny, nx;

    Node v;

    while(!q.empty()){
        v = q.front();
        q.pop();

        if(isEscaped(v.y, v.x)){
            cout<<v.dis<<"\n";
            return;
        }

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx) && !node[ny][nx].visited && (v.dis+1 < node[ny][nx].fireDis || node[ny][nx].fireDis == 0)){
                node[ny][nx].visited = true;
                node[ny][nx].dis = v.dis + 1;
                q.push(node[ny][nx]);

                if(isEscaped(ny, nx)){
                    cout<<node[ny][nx].dis<<"\n";
                    return;
                }
            }

        }

    }

    cout<<"IMPOSSIBLE\n";


}

void fireBfs(){
    int ny, nx;

    Node v;

    while(!qfire.empty()){
        v = qfire.front();
        qfire.pop();

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx) && !node[ny][nx].fireVisited){
                node[ny][nx].fireVisited = true;
                node[ny][nx].fireDis = v.fireDis + 1;
                qfire.push(node[ny][nx]);
            }
        }

    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> r >> c;

    char temp;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> temp;
            node[i][j].setNode(i, j , temp);

            if(node[i][j].value == 'F'){
                node[i][j].fireDis = 1;
                node[i][j].visited = true;
                qfire.push(node[i][j]);
            }else if(node[i][j].value == 'J'){
                node[i][j].dis = 1;
                node[i][j].visited = true;
                q.push(node[i][j]);
            }

        }
    }

    fireBfs();

    bfs();

    
}
