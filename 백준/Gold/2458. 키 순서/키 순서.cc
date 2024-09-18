// 2458
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;


int n, m;
bool adj[501][501];
bool visited[501];


void dfs(int x){
    for(int i = 1; i<=n; i++){
        if(adj[x][i] && !visited[i]){
            visited[i] = true;
            dfs(i);
            // visited[i] = false;
        }
    }
}

void rdfs(int x){
    for(int i = 1; i<=n; i++){
        if(adj[i][x] && !visited[i]){
            visited[i] = true;
            rdfs(i);
            // visited[i] = false;
        }
    }
}

bool flag;
int cnt;

void reset(){
    for(int i = 1; i<=n; i++){
        visited[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a][b] = true;
    }

    for(int i = 1; i<=n; i++){
        visited[i] = true;
        dfs(i);
        rdfs(i);
        flag = false;

        for(int j = 1; j<=n; j++){
            if(!visited[j]){
                flag = true;        // 순서 모름
                break;
            }
        }

        if(!flag){
            cnt++;
        }

        reset();
    }

    cout<<cnt;
}
