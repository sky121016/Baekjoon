// 16946
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <cstring>
#include<stack>
#include<string>

using namespace std;

int n, m;


class Node{
public:
    int y, x;
    char value;
    bool visited;
    int section;

    void setNode(int y, int x, char v){
        this->y = y;
        this->x = x;
        value = v;
        visited = false;
        section = 0;
    }
};

Node node[1001][1001];
int ans[1001][1001];
int sect;
vector<int> sectionSize;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

bool canVisit(int ny, int nx){
    return ny >= 0 && ny < n && nx >= 0 && nx < m && !node[ny][nx].visited && node[ny][nx].value == '0';
}

void bfs(Node& V){
    queue<Node> q;
    V.visited = true;
    V.section = sect;
    q.push(V);
    int cnt = 1;

    Node v;

    while(!q.empty()){
        v = q.front();
        q.pop();

        int ny, nx;

        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];

            if(canVisit(ny, nx)){
                node[ny][nx].visited = true;
                node[ny][nx].section = sect;
                cnt++;
                q.push(node[ny][nx]);
            }
        }

    }

    sectionSize.push_back(cnt);
}


void result(int y, int x){
    int ny, nx;
    vector<int> s;
    for(int i = 0; i<4; i++){
        ny = y + dir[i][0];
        nx = x + dir[i][1];

        bool sectionVisited = false;
        
        if(ny >= 0 && ny < n && nx >= 0 && nx < m && node[ny][nx].value == '0'){
            for(int k = 0; k<s.size(); k++){
                if(s[k] == node[ny][nx].section){
                    sectionVisited = true;
                }
            }
            if(!sectionVisited){
                s.push_back(node[ny][nx].section);
                ans[y][x] += sectionSize[node[ny][nx].section];
            }


        }
    }

    ans[y][x] ++;
    ans[y][x] %= 10;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    sectionSize.push_back(0);

    char temp;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);
        }
    }

    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(node[i][j].value == '0' && !node[i][j].visited){
                sect++;
                bfs(node[i][j]);
            }
        }
    }

    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(node[i][j].value == '1'){
                result(i, j);
            }

            cout<<ans[i][j];
        }
        cout<<"\n";
    }



}

