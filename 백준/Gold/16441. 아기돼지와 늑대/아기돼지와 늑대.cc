// 16441
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

class Node{
public:
    int x, y;
    bool visited;
    char land;

    void setNode(int y, int x, char l){
        this->y = y;
        this->x = x;
        land = l;
        visited = false;
    }
};


int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

vector< pair<int, int> > wolf;
Node node[101][101];
int n, m;

bool canVisit(int ny, int nx){
    return (!node[ny][nx].visited && ny >= 0 && ny < n && nx >= 0 && nx < m && (node[ny][nx].land == '+' || node[ny][nx].land == '.'));
}

void bfs(Node& V){
    queue<Node> q;

    V.visited = true;
    q.push(V);


    Node v;

    while(!q.empty()){
        v = q.front();
        q.pop();

        int ny, nx;
        int ty, tx;
        for(int i = 0; i<4; i++){
            ny = v.y + dir[i][0];
            nx = v.x + dir[i][1];


            while (node[ny][nx].land == '+'){
                
                ty = ny + dir[i][0];
                tx = nx + dir[i][1];

                if(node[ty][tx].land == '+'){
                    ny = ty;
                    nx = tx;
                }else if(node[ty][tx].land == '.' || node[ty][tx].land == 'W'){
                    ny = ty;
                    nx = tx;
                    break;
                }else{
                    break;
                }
                
            }

            if(canVisit(ny, nx) && node[ny][nx].land != '#'){
                node[ny][nx].visited = true;
                q.push(node[ny][nx]);
            }


        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    char temp;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> temp;
            node[i][j].setNode(i, j, temp);

            if(temp == 'W'){
                wolf.push_back(make_pair(i, j));
            }
        }
    }


    for(int i = 0; i<wolf.size(); i++){
        bfs(node[wolf[i].first][wolf[i].second]);
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if((node[i][j].land == '.') && !node[i][j].visited){
                cout<<"P";
            }else{
                cout<<node[i][j].land;
            }
        }
        cout<<"\n";
    }
}



