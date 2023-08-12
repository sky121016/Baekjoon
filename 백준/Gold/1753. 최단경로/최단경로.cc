// 1753 최단경로
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int V, E;
int K;                      // 시작점

int dist[20001];

vector< pair<int, int> > Linked[20001];     // 가중치, 정점

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

void shortestPath(){
    dist[K] = 0;
    pq.push(make_pair(dist[K], K));     // 가중치, 도착정점

    pair<int, int> v;                   // 현재 정점
    int vIdx, vWei;

    while(!pq.empty()){
        v = pq.top();
        pq.pop();

        vWei = v.first;
        vIdx = v.second;

        for(int i = 0; i < Linked[vIdx].size(); i++){
            pair<int, int> next = Linked[vIdx][i];           // 다음 정점
            int nextWei = Linked[vIdx][i].first;             // 다음 정점 가중치
            int nextIdx = Linked[vIdx][i].second;            // 다음 정점 인덱스

            if (dist[vIdx] + nextWei < dist[nextIdx]){      // 현재까지의 거리 + 다음 정점까지의 가중치 < 다음 정점까지의 거리
                dist[nextIdx] = dist[vIdx] + nextWei;
                pq.push(make_pair(dist[nextIdx], nextIdx));
            }
        }
    }

    for(int i = 1; i<=V; i++){
        if(dist[i] == 300001){
            cout<<"INF"<<"\n";
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
    cin >> K;           // 시작점

    int u, v, w;

    for(int i = 1; i<=V; i++){
        dist[i] = 300001;
    }

    for(int i = 1; i<=E; i++){
        cin >> u >> v >> w;
        Linked[u].push_back(make_pair(w,v));    // 연결리스트
    }

    shortestPath();


}