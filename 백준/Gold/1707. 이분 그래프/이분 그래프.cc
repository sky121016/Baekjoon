#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

using namespace std;

vector<int> adj[20101];
string str = "YES";
int k;
int v, e;

bool ans[20101];
bool visited[20101];


void bfs(int start){
    queue<int> q;
    visited[start] = true;
    q.push(start);

    int V;
    while(!q.empty()){
        V = q.front();
        q.pop();

        for(int i = 0; i < adj[V].size(); i++){
            int next = adj[V][i];
            if(!visited[next]){
                ans[next] = !ans[V];
                visited[next] = true;
                q.push(next);
            }else{
                if(ans[next] != !ans[V]){
                    str = "NO";
                    break;
                }
            }
        }
    }
}

void reset(){
    for(int i = 1; i<=v; i++){
        ans[i] = false;
        visited[i] = false;

        adj[i].clear();
    }

    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;

    int a, b;

    while(k > 0){
        cin >> v >> e;

        str = "YES";

        for(int i = 0; i<e; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i = 1; i<=v; i++){
            if(!visited[i]){
                bfs(i);
            }

            if(str == "NO"){
                break;
            }
        }



        cout << str << "\n";

        k--;

        reset();
    }
}
