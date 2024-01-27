// 16928 뱀
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class Board{
public:

    int value;
    bool visited;
    int cnt;

    void setNode(char value){
        this->value = value;
        visited = false;
    }

};

int dice[7] = {0, 1, 2, 3, 4, 5, 6};

Board b[101];
int n, m;


void bfs(Board& start){
    queue<Board> q;
    q.push(start);
    start.visited = true;
    start.cnt = 1;


    int nx;
    Board v;

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<7; i++){
            nx = v.value + i;                   
            if(!b[nx].visited && nx <=100){
                b[nx].visited = true;
                b[nx].cnt = v.cnt + 1;
                q.push(b[nx]);
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i<101; i++){
        b[i].setNode(i);
    }

    int x, y;
    for(int i = 0; i<n; i++){       // 사다리
        cin>>x>>y;
        b[x].value = y;
    }
    for(int i = 0; i<m; i++){       // 뱀
        cin>>x>>y;
        b[x].value = y;
    }

    bfs(b[1]);

    cout<<b[100].cnt;

}