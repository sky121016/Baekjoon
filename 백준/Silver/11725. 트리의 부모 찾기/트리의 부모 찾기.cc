// 11725
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;
vector<int> v[101010];
int parent[101010];
bool visited[101010];

void dfs(int num, int p){
    visited[num] = true;
    for(int i = 0; i<v[num].size(); i++){
        if(!visited[v[num][i]]){
            dfs(v[num][i], num);
        }
    }
    parent[num] = p;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int a, b;
    for(int i = 0; i<n-1; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1, 1);
    
    for(int i = 2; i<=n; i++){
        cout << parent[i] << "\n";
    }
}

