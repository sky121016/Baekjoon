// 16173 점프왕 쩰리 (Small)

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Map{
public:
    int x, y;
    int value;
    bool visited;
    void setMap(int y, int x, int v){
        this->y = y;
        this->x = x;
        this->value = v;
        visited = false;
    }
};

int n;
Map map[3][3];


int dir[2][2] = {
    {0, 1},
    {1, 0}
};

bool canVisit(int y, int x){
    return (y >= 0 && y < n && x >= 0 && x < n);
}


void bfs(){
    queue<Map> q;
    q.push(map[0][0]);
    map[0][0].visited = true;


    int ny, nx;
    Map v;

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<2; i++){
            ny = v.y + (dir[i][0] * v.value);       // v.value만큼 이동
            nx = v.x + (dir[i][1] * v.value);

            if(!map[ny][nx].visited && canVisit(ny, nx)){
                map[ny][nx].visited = true;
                q.push(map[ny][nx]);
            }
        }
    }

    if(map[n-1][n-1].visited){
        cout<<"HaruHaru";
    }else{
        cout<<"Hing";
    }

}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;
    int temp;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> temp;
            map[i][j].setMap(i, j, temp);
        }
    }

    bfs();


}



