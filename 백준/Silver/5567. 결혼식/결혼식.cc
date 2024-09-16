// 5567
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int n, m;
int visited[501];
int dis[501];
vector<int> friends[501];
int cnt;

void bfs(int V){
    queue<int> q;
    visited[V] = true;
    dis[V] = 0;
    q.push(V);

    int v;
    
    while(!q.empty()){
        v = q.front();
        q.pop();


        int next;
        for(int i = 0; i<friends[v].size(); i++){
            next = friends[v][i];

            if(!visited[next] && dis[next] > dis[v] + 1){
                dis[next] = dis[v] + 1;
                visited[next] = true;
                q.push(next);
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
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    fill(dis, dis+n+1, 501);

    bfs(1);

    for(int i = 2; i<=n; i++){
        if(dis[i] <= 2){
            cnt++;
        }
    }

    cout<<cnt;
}