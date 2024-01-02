// 2178
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int V;
int E;

bool visited[101];
vector<int> graph[101];
int cnt;


void dfs(int v){
    visited[v] = true;
    
    for(int i = 0; i<graph[v].size(); i++){
        if(!visited[graph[v][i]]){
            dfs(graph[v][i]);
            cnt++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;

    int a, b;

    for(int i = 0; i<E; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    cout << cnt;
}
