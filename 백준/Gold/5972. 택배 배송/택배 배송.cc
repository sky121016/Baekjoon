// 5972
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>

using namespace std;

int n, m;
vector < pair <int, int > > edge [50001];
vector<int> dist;


void shortest(){
    queue<int> q;

    q.push(1);

    int u, v;
    while(!q.empty()){
        u = q.front();
        q.pop();

        for(int i = 0; i<edge[u].size(); i++){
            v = edge[u][i].first;
            if(dist[v] > dist[u] + edge[u][i].second){
                dist[v] = dist[u] + edge[u][i].second;
                q.push(v);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int a, b, c;
    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
        edge[b].push_back(make_pair(a, c));
    }

    for(int i = 0; i<=n; i++){
        dist.push_back(999999999);
    }

    dist[1] = 0;

    shortest();

    cout<<dist[n];


}