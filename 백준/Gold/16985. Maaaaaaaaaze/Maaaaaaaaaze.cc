

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
    int y, x, z;
    bool value;
    bool visited;
    int dis;
    
    void setNode(int y, int x, int z, bool v){
        this->y = y;
        this->x = x;
        this->z = z;
        value = v;
        dis = 0;
        visited = false;
    }
};


Node node[6][6][6];
Node rNode[6][6][6];

bool selected[6];
int order[6];
int rotated[6];


void rotate(int k, int r){
    if(r == 1){
        for(int i = 0; i<5; i++){
            for(int j = 0; j<5; j++){
                int v = node[k][i][j].value;
                rNode[order[k]][i][j].setNode(i, j, order[k], v); 
            }
        }
    }else if(r == 2){
        for(int i = 0; i<5; i++){
            for(int j = 0; j<5; j++){
                int v = node[k][i][j].value;
                rNode[order[k]][j][4 - i].setNode(j, 4 - i, order[k], v);
            }
        }
    }else if(r == 3){
        for(int i = 0; i<5; i++){
            for(int j = 0; j<5; j++){
                int v = node[k][i][j].value;
                rNode[order[k]][4 - i][4 - j].setNode(4 - i, 4 - j, order[k], v);
            }
        }
    }else if(r == 4){
        for(int i = 0; i<5; i++){
            for(int j = 0; j<5; j++){
                int v = node[k][i][j].value;
                rNode[order[k]][4 - j][i].setNode(4 - j, i, order[k], v);
            }
        }
    }

}

// 판 설정하기
void setMaze(){
    for(int i = 0; i<5; i++){
        rotate(i, rotated[i]);
    }
}



int ans = 9999999;
int disTemp = 9999999;
bool gotAns;

void reset(){
    for(int k = 0; k<5; k++){
        for(int i = 0; i<5; i++){
            for(int j = 0; j<5; j++){
                node[k][i][j].visited = false;
                node[k][i][j].dis = 0;
            }
        }
    }



    // for(int i = 0; i<6; i++){
    //     selected[i] = false;
    // }
}

int dir[6][3] = {
    {0,0,-1},
    {-1,0,0},
    {0,1,0},
    {0,0,1},
    {1,0,0},
    {0,-1,0},
};

bool canVisit(int ny, int nx, int nz){
    return (ny>=0 && ny<5 && nx>=0 && nx<5 && nz>=0 && nz<5 && !rNode[nz][ny][nx].visited && rNode[nz][ny][nx].value);
}

void bfs(){
    queue<Node> q;
    rNode[0][0][0].visited = true;
    rNode[0][0][0].dis = 0;
    q.push(rNode[0][0][0]);

    disTemp = 9999999;

    Node v;
    int ny, nx, nz;

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<6; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];
            nz = v.z + dir[i][2];

            if(canVisit(ny, nx, nz)){
                rNode[nz][ny][nx].visited = true;
                rNode[nz][ny][nx].dis = v.dis + 1;
                q.push(rNode[nz][ny][nx]);

                if(ny == 4 && nx == 4 && nz == 4){
                    disTemp = rNode[nz][ny][nx].dis;
                    return;
                }
            }
        }
    }
}

// 회전 정하기
void setRotate(int cnt){        // cnt = k
    if(cnt == 5){
        setMaze();

        if(rNode[0][0][0].value && rNode[4][4][4].value){
            bfs();

            if(ans > disTemp){
                ans = disTemp;
            }

            reset();
        }

        return;
    }

    for(int i = 1; i<=4; i++){
        rotated[cnt] = i;
        setRotate(cnt + 1);
    }
}

// 판의 순서 정하기
void setOrder(int cnt){
    if(cnt == 5){
        setRotate(0);
        return;
    }

    for(int i = 0; i<5; i++){
        if(selected[i]){continue;}
        selected[i] = true;
        order[i] = cnt;
        setOrder(cnt + 1);
        selected[i] = false;
        order[i] = -1;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    bool temp;
    for(int k = 0; k<5; k++){
        for(int i = 0; i<5; i++){
            for(int j = 0; j<5; j++){
                cin >> temp;
                node[k][i][j].setNode(i, j, k, temp);
            }
        }
    }

    setOrder(0);

    if(ans != 9999999){
        cout << ans;
    }else{
        cout << -1;
    }
    
}
