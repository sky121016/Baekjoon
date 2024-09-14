// 17141
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
    int dis;

    void setNode(int y, int x, int value){
        this->y = y;
        this->x = x;
        this->value = value;
        visited = false;
        dis = 0;
    }

};

Node node[51][51];
int N, M;
vector<pair<int, int> > virus;
int virusSelected[11];

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};


bool canVisit(int ny, int nx){
    return(!node[ny][nx].visited && ny>=0 && ny<N && nx>=0 && nx<N && node[ny][nx].value != 1);
}

int maxTime;
int ans = 3000;

queue<Node> q;
void bfs(){
    Node v;
    int ny, nx;

    while(!q.empty()){
        v = q.front();
        q.pop();
        
        for (int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)){
                node[ny][nx].dis = v.dis + 1;
                node[ny][nx].visited = true;
                q.push(node[ny][nx]);

                if(maxTime < node[ny][nx].dis){
                    maxTime = node[ny][nx].dis;
                }
            }
        }
    }
}

void reset(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            node[i][j].dis = 0;
            node[i][j].visited = false;
        }
    }

}


void select(int v, int cnt){
    if(cnt == M){
        for(int i = 0; i<virus.size(); i++){
            if(virusSelected[i]){
                int ny = virus[i].first;
                int nx = virus[i].second;
                node[ny][nx].visited = true;
                q.push(node[ny][nx]);
            }
        }

        bfs();

        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                // 다 안퍼짐
                if(!node[i][j].visited && node[i][j].value != 1){
                    maxTime = -1;
                    break;
                }
            }
            if(maxTime == -1){
                break;
            }
        }

        if(maxTime != -1){
            ans = min(ans, maxTime);
        }
        reset();
            
        maxTime = -1;
        return;
    }
    
    for(int i = v; i<virus.size(); i++){
        if(!virusSelected[i]){
            virusSelected[i] = true;
            select(i, cnt+1);
            virusSelected[i] = false;
        }
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int temp;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);

            if(temp == 2){
                virus.push_back(make_pair(i,j));
            }
        }
    }

    select(0,0);

    if(ans != 3000){
        cout<<ans;
    }else{
        cout << -1;
    }
}

