#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

int n;
int m;

int a, b;
vector<int> adj[2001];
int ans;
bool visited[2001];

void dfs(int cnt, int v){
    if(cnt == 4){
        ans = 1;
        return;
    }

    for(int i = 0; i<adj[v].size(); i++){
        int next = adj[v][i];
        if(!visited[next]){
            visited[next] = true;
            dfs(cnt+1, next);
            visited[next] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i<m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i<n; i++){
        visited[i] = true;
        dfs(0, i);
        visited[i] = false;

        if(ans == 1){
            break;
        }
    }

    cout << ans;
}
