// 11053
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int V, E;
int K;
vector<pair<int, int>> adj[20001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

int INF = 99999999;
int dist[20001]; // k에서부터 거리

void shortest(){
    pair<int, int> v;

    while(!pq.empty()){
        v = pq.top();
        pq.pop();


        for(int i = 0; i<adj[v.second].size(); i++){
            int w = adj[v.second][i].first;     // v에서 도착지까지 가중치
            int nIdx = adj[v.second][i].second; // 도착지

            if(dist[nIdx] > dist[v.second] + w){
                dist[nIdx] = dist[v.second] + w;
                pq.push(make_pair(dist[nIdx],nIdx));
            }
        }
    }


    for(int i = 1; i<=V; i++){
        if(dist[i] == INF){
            cout<<"INF\n";
        }else{
            cout<<dist[i]<<"\n";
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    cin >> K;

    for(int i = 1; i <= V; i++){
        dist[i] = INF;
    }
    dist[K] = 0;

    int u, v, w;
    for(int i = 0; i<E; i++){
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(w, v));
    }

    pq.push(make_pair(0, K));

    shortest();
}
