// 11724
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> node[1001];
bool visited[1001];
int n, m;
int cnt;


void bfs(int v){
    queue<int> q;

    visited[v] = true;
    q.push(v);


    while(!q.empty()){
        v = q.front();
        q.pop();
        for(int i = 0; i<node[v].size(); i++){
            int u = node[v][i];
            if(!visited[u]){
                visited[u] = true;
                q.push(u);
            }
        }

    }


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int a, b;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    for(int j = 1; j<=n; j++){
        if(!visited[j]){
            cnt++;
            bfs(j);
        }
    }

    cout<<cnt;
}

