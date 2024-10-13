// 17265
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;


int n;
int m;
int p, q;
vector<int> e[1001];
vector<int> f[1001];

bool visited[1001];
int cnt;



void bfs(int x){
    queue<int> q;
    visited[x] = true;
    
    q.push(x);

    int next, nnext;

    int cur;
    while(!q.empty()){
        cur = q.front();
        q.pop();

        for(int i = 0; i<f[cur].size(); i++){
            next = f[cur][i];

            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }

        for(int i = 0; i<e[cur].size(); i++){
            next = e[cur][i];
            for(int j = 0; j<e[next].size(); j++){
                nnext = e[next][j];
                if(!visited[nnext]){
                    visited[nnext] = true;
                    q.push(nnext);
                }
            }            
        }


    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    char ef;
    for(int i = 0; i<m; i++){
        cin >> ef >> p >> q;
        if(ef == 'E'){
            e[p].push_back(q);
            e[q].push_back(p);
        }else{
            f[p].push_back(q);
            f[q].push_back(p);
        }
    }

    for (int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt++;
            bfs(i);
        }
    }

    cout << cnt;
}



