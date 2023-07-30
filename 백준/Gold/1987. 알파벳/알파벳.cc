// 1987 알파벳
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Map{
public:
    int x, y;
    bool visited;
    char al;

    void setMap(int y, int x, char a){
        this->y = y;
        this->x = x;
        al = a;
        visited = false;
    }
};

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};


int r, c;
Map map[21][21];
bool alpha[26];
int maxCnt;

bool canVisit(int ny, int nx){
    return (!map[ny][nx].visited && !alpha[map[ny][nx].al-65] && ny >= 0 && ny < r && nx >= 0 && nx < c);
}

void dfs(Map& v, int cnt){

    if(cnt>maxCnt){maxCnt = cnt;}
    
    int ny, nx;

    for (int i = 0; i < 4; i++){
        ny = v.y + dir[i][0];
        nx = v.x + dir[i][1];

        if(canVisit(ny, nx)){
            map[ny][nx].visited = true;
            alpha[map[ny][nx].al-65] = true;

            dfs(map[ny][nx], cnt+1);

            map[ny][nx].visited = false;
            alpha[map[ny][nx].al-65] = false;
        }
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    char temp;

    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            cin >> temp;
            map[i][j].setMap(i, j, temp);
        }
    }

    alpha[map[0][0].al-65] = true;
    dfs(map[0][0], 1);

    cout<<maxCnt;
    
}
