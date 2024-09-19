// 2638
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
    int value;      
    bool isOutside;
    int airCnt;

    void setNode(int y, int x, int v){
        this-> y = y;
        this-> x = x;
        value = v;
        visited = false;
        isOutside = false;
    } 
};


Node node[101][101];
int n, m;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return (ny >= 0 && ny < n && nx >= 0 && nx < m && !node[ny][nx].visited);
}

void reset(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            node[i][j].visited = false;
            node[i][j].isOutside = false;
        }
    }
}


void dfs(int y, int x){
    int ny, nx;
    for(int i = 0; i<4; i++){
        ny = y + dir[i][0];
        nx = x + dir[i][1];

        // find air area
        if(canVisit(ny, nx) && node[ny][nx].value == 0){
            node[ny][nx].visited = true;
            node[ny][nx].isOutside = true;
            dfs(ny, nx);
        }
    }
}


void getTouchArea(){
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            node[i][j].airCnt =0;
            if(node[i][j].value == 1){
                for(int k = 0; k<4; k++){
                    int ny = i + dir[k][0];
                    int nx = j + dir[k][1];

                    // 외부공기 접촉
                    if(ny >= 0 && ny < n && nx >= 0 && nx < m && node[ny][nx].isOutside){
                        node[i][j].airCnt++;
                    }
                }
            }
        }
    }


}


int total;
int ans;
queue<Node> q;

void melt(){
    Node v;
    while(!q.empty()){
        v = q.front();
        q.pop();
        int ny = v.y;
        int nx = v.x;
        node[ny][nx].value = 0;
        node[ny][nx].airCnt = 0;
        node[ny][nx].isOutside = true;

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

            if(temp == 1){
                total ++;
            }
        }
    }

    // 녹이기

    while(total > 0){
        dfs(0, 0);
        getTouchArea();


        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(node[i][j].value == 1 && node[i][j].airCnt >= 2){
                    q.push(node[i][j]);
                    total--;
                }
            }
        }

   
        melt();
        ans++;
        reset();

    }

    cout << ans;
}