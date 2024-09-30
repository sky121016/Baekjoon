// 7562
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
    bool visited;
    int cnt;

    void setNode(int y, int x){
        this->y = y;
        this->x = x;
        cnt = 0;
        visited = false;
    }
};


int dir[8][2] = {
    {-2, 1},
    {-1,2},
    {1,2},
    {2,1},
    {2,-1},
    {1,-2},
    {-1,-2},
    {-2,-1},
};

int n;
int t;
int a, b;
int c, d;
Node node[301][301];
int ans;

bool canVisit(int ny, int nx){
    return (ny >= 0 && ny < n && nx >= 0 && nx < n && !node[ny][nx].visited);
}

void reset(){
    ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            node[i][j].visited = false;
            node[i][j].cnt = 0;
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

        for(int i = 0; i<8; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];
            

            if(canVisit(ny, nx)){
                node[ny][nx].visited = true;
                node[ny][nx].cnt = v.cnt + 1;
                q.push(node[ny][nx]);

                if(ny == c && nx == d){
                    ans = node[ny][nx].cnt;
                    return;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for(int i = 0; i<t; i++){
        cin >> n;
        cin >> a >> b;
        cin >> c >> d;

        if(a==c && b==d){
            cout << "0\n";
            continue;
        }

        for(int j = 0; j<n; j++){
            for(int k = 0; k<n; k++){
                node[j][k].setNode(j, k);
            }
        }

        bfs(node[a][b]);

        cout << ans << "\n";
    }
}
