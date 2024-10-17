// 17265
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n, m, R;
vector<int> adj[101010];
bool visited[101010];
int order[101010];
int cnt;

void dfs(int r){

    for(int i = 0; i<adj[r].size(); i++){
        int next = adj[r][i];
        if(!visited[next]){
            cnt++;
            order[next] = cnt;
            visited[next] = true;
            dfs(next);
        }
    }

    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> R;

    int u, v;

    for(int i = 0; i<m; i++){
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    for(int i = 1; i<=n; i++){
        sort(adj[i].rbegin(), adj[i].rend());
    }

    visited[R] = true;
    cnt = 1;
    order[R] = cnt;
    dfs(R);


    for(int i = 1; i<=n; i++){
        cout << order[i] << "\n";
    }
}
