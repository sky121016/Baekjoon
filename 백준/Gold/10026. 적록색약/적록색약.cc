// 10026
#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

class Node{
public:
    int x,y;
    char color;
    bool visited;

    void setNode(int y, int x, char c){
        this->y = y;
        this->x = x;
        color = c;
        visited = false;
    }

    void setNode2(){
        if(color == 'G'){
            color = 'R';
        }
        visited = false;
    }
};

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};



Node rgb[101][101];
int n;
int ans1, ans2;


bool canVisit(int y, int x){
    return (!rgb[y][x].visited && y < n && y >= 0 && x < n && x >= 0);
}

queue<Node> q;
Node v;

void bfs(Node& V){
    V.visited = true;
    q.push(V);


    while(!q.empty()){
        v = q.front();
        q.pop();

        int ny, nx;
        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx) && rgb[ny][nx].color == v.color){
                rgb[ny][nx].visited = true;
                q.push(rgb[ny][nx]);
            }
        }
    }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    char temp;

    // first
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> temp;
            rgb[i][j].setNode(i, j, temp);
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(canVisit(i,j)){
                ans1++;
                bfs(rgb[i][j]);
            }
        }
    }

    while(!q.empty()){
        q.pop();
    }


    // second
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            rgb[i][j].setNode2();
        }
    }

    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(canVisit(i,j)){
                ans2++;
                bfs(rgb[i][j]);
            }
        }
    }

    cout << ans1 << " " << ans2 << "\n";
}
