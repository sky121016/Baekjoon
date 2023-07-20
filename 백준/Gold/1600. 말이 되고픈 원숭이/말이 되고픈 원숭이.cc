
// 1600 말이 되고픈 원숭이
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Node{
public:
    int x, y;
    int jump;
    char value;

    void setNode(int y, int x, char value){
        this->y = y;
        this->x = x;
        this->value = value;
        jump = 0;
    }
};

Node node[201][201];
int visited[32][201][201];

int k, w, h;

int dir[12][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},

    {-1,-2},            // 말 이동
    {-2,-1},
    {-2,1},
    {-1,2},
    {1,2},
    {2,1},
    {2,-1},
    {1,-2}
};


bool canVisit(int ny, int nx){
    return (nx >= 0 && nx < w && ny >= 0 && ny < h);
}



int bfs(){
    queue<Node> q;

    
    q.push(node[0][0]);

    Node v;
    int ny, nx;


    while(!q.empty()){
        v = q.front();
        int jump = v.jump;
        q.pop();

        if(v.y == h-1 && v.x == w-1){
            return visited[jump][h-1][w-1];
        }

        for(int i = 0; i<12; i++){
            
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];


            if(!canVisit(ny,nx)){continue;}

            if(i >= 4 && jump >= k){continue;}


            if(i >= 4){
                node[ny][nx].jump = jump+1;
            }else{
                node[ny][nx].jump = jump;
            }

            int nj = node[ny][nx].jump;

            if(node[ny][nx].value == '0' && visited[nj][ny][nx] < 1){

                visited[nj][ny][nx] = visited[jump][v.y][v.x] + 1;

                q.push(node[ny][nx]);
            }
        
        }
    }

    return -1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> k;
    cin >> w >> h;


    char temp;
    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
        }
    }

    cout<<bfs()<<"\n";


}

