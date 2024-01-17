// 1806
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
public:
    int x, y;
    bool visited;
    bool sink;
    int height;
    void setNode(int y, int x, int h){
        this->y = y;
        this->x = x;
        height = h;
        visited = false;
        sink = false;
    }
};

int n;
Node node[101][101];
int minRain = 101;
int maxRain = 0;
int tempH;
int h;
int cnt;
vector<int> safezone;


int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return (!node[ny][nx].visited && !node[ny][nx].sink && ny < n && ny >= 0 && nx < n && nx >= 0);
}

queue<Node> q;

void bfs(Node& v){

    v.visited = true;
    q.push(v);

    int ny, nx;
    Node u;

    while(!q.empty()){
        u = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            ny = u.y + dir[i][0];
            nx = u.x + dir[i][1];

            if(canVisit(ny, nx)){
                node[ny][nx].visited = true;
                q.push(node[ny][nx]);
            }

        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> tempH;
            if(tempH < minRain){
                minRain = tempH;
            }
            if(tempH > maxRain){
                maxRain = tempH;
            }
            node[i][j].setNode(i, j, tempH);
        }
    }

    
    h = 0;

    while (h <= maxRain){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(!node[i][j].sink && node[i][j].height == h){
                    node[i][j].sink = true;
                }
            }
        }


        for (int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!node[i][j].sink && !node[i][j].visited){
                    bfs(node[i][j]);
                    cnt++;
                }
            }
        }

        while(!q.empty()){
            q.pop();
        }
     

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(node[i][j].visited){
                    node[i][j].visited = false;
                }
            }
        }


        safezone.push_back(cnt);
        cnt = 0;
        h++;
    }


    cout<<*max_element(safezone.begin(), safezone.end());
}




