// 24444
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;



int N, M, R;
vector<int> node[101010];
bool visited[101010];
int cnt = 1;
int order[101010];

void bfs(int v){
    queue<int> q;
    visited[v] = true;
    order[v] = cnt;
    q.push(v);

    int next;
    while(!q.empty()){
        next = q.front();
        q.pop();

        for(int i = 0; i<node[next].size(); i++){
            if(!visited[node[next][i]]){
                visited[node[next][i]] = true;
                q.push(node[next][i]);
                cnt++;
                order[node[next][i]] = cnt;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> R;

    int a, b;

    for(int i = 0; i<M; i++){
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    for(int i = 1; i<=N; i++){
        sort(node[i].begin(),node[i].end());
    }

    bfs(R);

    for(int i = 1; i<=N; i++){
        cout<<order[i]<<"\n";
    }
}
