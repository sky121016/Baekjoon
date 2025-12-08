// 15649
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

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


int n, k, s, x, y;
priority_queue<pair<int, pair<int , int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq[2];
Node node[201][201];


int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool canVisit(int ny, int nx){
    return (0<=ny && ny<=n && 0<=nx && nx<=n && !node[ny][nx].visited);
}

void bfs(){
    while(s > 0){
        int idx = s % 2;    // pq 두개 번갈아 가면서 쓰기
        
        int ny, nx;
        Node v;

        while(!pq[idx].empty()){
            int vy = pq[idx].top().second.first;
            int vx = pq[idx].top().second.second;
            v = node[vy][vx];

            pq[idx].pop();

            for(int i = 0; i<4; i++){
                ny = v.y + dir[i][0];
                nx = v.x + dir[i][1];

                if(canVisit(ny, nx)){
                    node[ny][nx].value = v.value;
                    node[ny][nx].visited = true;
                    pq[(s+1)%2].push(make_pair(node[ny][nx].value,make_pair(ny, nx)));
                }
            }


        }


        s--;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    int temp;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);

            if(temp != 0){
                pq[0].push(make_pair(temp, make_pair(i, j)));
                node[i][j].visited = true;
            }
        }
    }

    cin >> s >> x >> y;


    bfs();


    // output 일반적인 y, x랑 반대 주의
    cout<<node[x][y].value;
}
