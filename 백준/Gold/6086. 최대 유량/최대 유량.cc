// 6086
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

int n;
int cap[60][60];
int flow[60][60];
int visited[60];
int minCap;
int res;
int ans;

void maxflow(){
    while(1){
        minCap = 1111;
        queue<int> q;
        q.push(1);

        for(int i = 0; i<60; i++){
            visited[i] = -1;
        }

        visited[1] = 1;

        while(!q.empty()){
            int v;
            v = q.front();
            q.pop();

            for(int i = 0; i<60; i++){
                int np = cap[v][i];
                if (np == 0){
                    continue;
                }

                if(cap[v][i] > flow[v][i] && visited[i] == -1){
                    visited[i] = v;
                    q.push(i);

                    if(i == 26){        // Z 도착
                        break;
                    }
                }
            }
        }


        if(visited[26] == -1){
            break;
        }

        int cur = 26;   // Z Index
        int next = 0;
        next = visited[cur];
        
        while(cur != 1){

            // 더 흘릴 수 있고 minCap이 크면
            if(cap[next][cur] > flow[next][cur] && minCap > cap[next][cur] - flow[next][cur]){
                minCap = cap[next][cur] - flow[next][cur];
            }
            cur = visited[cur];
            next = visited[cur];    


        }

        cur = 26;
        next = visited[cur];

        // flow update
        while(cur != 1){
            flow[next][cur] += minCap;
            flow[cur][next] -= minCap;
            cur = visited[cur];
            next = visited[cur];
        }

        ans += minCap;

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 'A' = 65;
    // A = 1번 index
    // index 구하려면 -64 해야함

    cin >> n;


    char a, b;
    int c;
    for (int i = 0; i < n; i++){
        cin >> a >> b >> c;
        cap[a-64][b-64] += c;
        cap[b-64][a-64] += c;
    }


    maxflow();

    cout<<ans;
}

