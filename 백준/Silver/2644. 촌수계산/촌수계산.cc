// 2644
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;
int m;
int a, b;
vector<int> family[101];
bool visited[101];
int ans;

void dfs(int v, int cnt){
    visited[v] = true;
    
    if(v == b){
        ans = cnt;
        return;
    }else{
        for(int i = 0; i<family[v].size(); i++){
            if(!visited[family[v][i]]){
                dfs(family[v][i], cnt + 1);
            }
        }
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> a >> b;
    cin >> m;

    int x, y;
    for(int i = 0; i<m; i++){
        cin >> x >> y;
        family[x].push_back(y);
        family[y].push_back(x);
    }

    dfs(a, 0);

    if(ans != 0){
        cout << ans;
    }else{
        cout << "-1";
    }
    // cout << dfs(a, 0);
}

