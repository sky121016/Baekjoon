#include <string>
#include <vector>

using namespace std;

bool visited[201];


void dfs(int v, vector<vector<int>> computers){
    visited[v] = true;
    
    for(int i = 0; i<computers[v].size(); i++){
        if(!visited[i] && computers[v][i] == 1){
            dfs(i, computers);
            // visited[i] = false;
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            dfs(i, computers);
            cnt++;
        }
    }
    
    return cnt;
}