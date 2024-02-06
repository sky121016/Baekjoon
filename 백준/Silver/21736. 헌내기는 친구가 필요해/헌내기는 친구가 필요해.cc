// 21736
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Node{
public:
    int x, y;
    bool visited;
    char value;

    void setNode(int y, int x, char v){
        this->y = y;
        this->x = x;
        value = v;
        visited = false;
    }
};

Node node[601][601];
int cnt;
int n, m;
char temp;
int Dx, Dy;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return (!node[ny][nx].visited && node[ny][nx].value != 'X' && ny < n && ny >= 0 && nx < m && nx >= 0);
}

void bfs(Node& v){
    queue<Node> q;
    v.visited = true;
    q.push(v);

    while(!q.empty()){
        v = q.front();
        q.pop();

        int ny, nx;
        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if (canVisit(ny, nx)){
                node[ny][nx].visited = true;
                q.push(node[ny][nx]);
                if(node[ny][nx].value=='P'){
                    cnt++;
                }
            }
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
            if(temp == 'I'){
                Dy = i;
                Dx = j;
            }
        }
    }

    bfs(node[Dy][Dx]);

    if(cnt == 0){
        cout<<"TT";
    }else{
        cout << cnt;
    }

}