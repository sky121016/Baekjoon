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
    int dis;

    void setNode(int y, int x, int v){
        this->y = y;
        this->x = x;
        value = v;
        visited = false;
        dis = 0;
    }
};


int n, m;
Node node[51][51];
int maxDis;
vector<int> sum;


int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};


bool canVisit(int ny, int nx){
    return (ny>=0 && ny<n && nx>=0 && nx<m && !node[ny][nx].visited && node[ny][nx].value != 0);
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
                node[ny][nx].dis = v.dis + 1;

                q.push(node[ny][nx]);


                if(maxDis < node[ny][nx].dis){
                    maxDis = node[ny][nx].dis;

                    sum.clear();
                    sum.push_back(V.value + node[ny][nx].value);
                }else if(maxDis == node[ny][nx].dis){
                    sum.push_back(V.value + node[ny][nx].value);
                }
            }
        }
    }
}

void reset(){
    for (int i = 0; i < n; i++){
        for(int j = 0; j<m; j++){
            node[i][j].visited = false;
            node[i][j].dis = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int temp;
    for (int i = 0; i < n; i++){
        for(int j = 0; j<m; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
        }
    }

    for (int i = 0; i < n; i++){
        for(int j = 0; j<m; j++){
            if(node[i][j].value != 0){
                bfs(node[i][j]);
                reset();
            }
        }   
    }

    cout << *max_element(sum.begin(), sum.end());
}
