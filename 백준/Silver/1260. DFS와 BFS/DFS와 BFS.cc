#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include <string.h>
using namespace std;

int N, M, V;
bool visited[1001];
vector<int> graph[1001];
queue<int> q;

int a, b;

void dfs(int v){
    visited[v] = true;
    cout << v << " ";

    for(int i = 0; i<graph[v].size(); i++){
        if(!visited[graph[v][i]]){
            dfs(graph[v][i]);
        }
    }
}



void bfs(int v){
    visited[v] = true;
    q.push(v);
    cout << v << " ";

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<graph[v].size(); i++){
            if(!visited[graph[v][i]]){
                q.push(graph[v][i]);
                visited[graph[v][i]] = true;
                cout << graph[v][i] << " ";
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;


    // 인접 정점 저장
    for(int i = 0; i<M; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    // 정점 번호 오름차순 정렬
    for(int j = 1; j <= N; j++){
        sort(graph[j].begin(), graph[j].end());
    }

    dfs(V);
    cout << "\n";
    memset(visited, false, sizeof(visited));

    bfs(V);

    
}

