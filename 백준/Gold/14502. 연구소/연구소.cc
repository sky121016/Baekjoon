// 14502
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
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


int N, M;
Node node[9][9];
Node nodeOrigin[9][9];
int maxCnt;


int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};



int tempCnt;

bool canVisit(int ny, int nx){
    return (!node[ny][nx].visited && ny >= 0 && ny < N && nx >= 0 && nx < M && node[ny][nx].value == 0);
}

void bfs(Node& V){
    queue<Node> q;

    V.visited = true;

    Node v;
    int ny, nx;
    // tempCnt = 1;
    
    q.push(V);

    while(!q.empty()){
        v = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];


            if(canVisit(ny, nx)){
                node[ny][nx].visited = true;
                node[ny][nx].value = 2;
                q.push(node[ny][nx]);
            }
        }

    }

    // if(maxCnt < tempCnt){
    //     maxCnt = tempCnt;
    // }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int temp;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
            nodeOrigin[i][j].setNode(i, j, temp);
        }
    }


    for(int i = 0; i<N*M; i++){
        if(node[i/M][i%M].value == 0){

            for(int j = i+1; j<N*M; j++){
                if(node[j/M][j%M].value == 0){

                    for(int k = j+1; k<N*M; k++){
                        if(node[k/M][k%M].value == 0){

                            node[i/M][i%M].value = 1;
                            node[j/M][j%M].value = 1;
                            node[k/M][k%M].value = 1;

                            // virus 퍼트리기
                            for(int y = 0; y < N; y++){
                                for(int x = 0; x < M; x++){
                                    if(node[y][x].value == 2){
                                        bfs(node[y][x]);
                                    }
                                }
                            }


                            tempCnt = 0;



                            for(int y = 0; y < N; y++){
                                for(int x = 0; x < M; x++){
                                    if(node[y][x].value == 0){
                                        tempCnt++;
                                    }
                                }
                            }


                            if(maxCnt<tempCnt){
                                maxCnt = tempCnt;
                            }


                            for(int y = 0; y < N; y++){
                                for(int x = 0; x < M; x++){
                                    node[y][x].visited = false;
                                    node[y][x].value = nodeOrigin[y][x].value;
                                }
                            }


                        }

                    }

                }

            } 
        }
    }

    cout << maxCnt;
}
