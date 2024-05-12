// 2152
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include <string.h>

using namespace std;

int n, m, s, t;
vector<int> edge[10101];
vector< vector<int> > scc;
int visited[10101];
int sccGroupNum[10101];
int groupCnt;
int cnt;
stack<int> st;

vector<int> connected_scc[10101];

int dp[10101];

int dfs(int v){
    visited[v] = cnt++;
    // cout<<visited[v];
    

    int val = visited[v];
    st.push(v);

    for(int i = 0; i<edge[v].size(); i++){
        int next = edge[v][i];
        if(visited[next] == -1){
            val = min(val, dfs(next));
        }else if(sccGroupNum[next] == -1){
            val = min(val, visited[next]);
        }
    }

    if(val == visited[v]){
        scc.push_back(vector<int> ());
        while(1){
            int target = st.top();
            st.pop();

            scc[groupCnt].push_back(target);
            sccGroupNum[target] = groupCnt;

            if(target == v){
                break;
            }
        }
        groupCnt++;
    }

    return val;
}

void bfs(){
    queue<int> q;

    q.push(sccGroupNum[s]);

    int next;

    dp[sccGroupNum[s]] = scc[sccGroupNum[s]].size();

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 0; i<connected_scc[cur].size(); i++){
            next = connected_scc[cur][i];

            if(dp[next] < dp[cur] + scc[next].size()){
                dp[next] = dp[cur] + scc[next].size();
                q.push(next);
            }
        }
    }
    
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> s >> t;

    int a, b;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        edge[a].push_back(b);
    }

    memset(visited, -1, sizeof(visited));
    memset(sccGroupNum, -1, sizeof(sccGroupNum));

    // scc 그룹
    for(int i = 1; i<=n; i++){
        if(visited[i] == -1){
            dfs(i);
        }
    }

    // scc끼리 연결된거 찾기
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<edge[i].size(); j++){
            int next = edge[i][j];
            if(sccGroupNum[next] != sccGroupNum[i]){       // 다른 scc로의 경로가 있으면
                connected_scc[sccGroupNum[i]].push_back(sccGroupNum[next]);
            }
        }
    }

    // dp update
    bfs();

    cout << dp[sccGroupNum[t]];
}

