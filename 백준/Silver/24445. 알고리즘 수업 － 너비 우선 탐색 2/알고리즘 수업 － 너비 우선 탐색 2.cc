#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n, m, r;
vector<int> adj[100010];
bool visited[100010];
int cnt = 1;
int order[101010];

void bfs(){
    queue<int> q;
    visited[r] = true;
    q.push(r);
    order[r] = cnt;
    cnt++;

    int v;


    while(!q.empty()){
        v = q.front();
        q.pop();
        
        int next;
        for(int i = 0; i<adj[v].size(); i++){
            next = adj[v][i];
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
                order[next] = cnt;
                cnt++;
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;

    int u, v;
    for(int i = 0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i<=n; i++){
        sort(adj[i].rbegin(), adj[i].rend());
    }

    bfs();

    for(int i = 1; i<=n; i++){
        cout << order[i] << "\n";
    }
}
