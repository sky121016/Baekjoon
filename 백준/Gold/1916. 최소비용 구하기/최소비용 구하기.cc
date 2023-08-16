// 1916 최소비용 구하기
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int N, M;
int first, last;
int dist[1001];
vector< pair<int, int> > bus[1001];     // 가중치, 정점
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;


void shortestPath(){
    dist[first] = 0;
    pq.push(make_pair(dist[first], first));     // 거리, 정점

    pair<int, int> v;               // 현재 정점
    int vDist;                      // 현재 정점까지의 거리
    int vI;                         // 현재 정점의 index

    int nW;
    int nI;
    while(!pq.empty()){
        v = pq.top();
        pq.pop();

        vDist = v.first;  
        vI = v.second; 

        if(dist[vI] < vDist){continue;}         // 저장된 최소거리보다  크면 넘어가기

        for(int i = 0; i<bus[vI].size(); i++){
            pair<int, int> n = bus[vI][i];
            nW = n.first;                   // 가중치
            nI = n.second;

            if(dist[vI] + nW < dist[nI]){
                dist[nI] = dist[vI] + nW;
                pq.push(make_pair(dist[nI], nI));
            }
        }
    }

    cout<<dist[last]<<"\n";



}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    fill(dist, dist + N + 1, 987654321);

    int v, u, w;
    for(int i = 0; i<M; i++){
        cin >> v >> u >> w;         // 출발, 도착, 가중치
        bus[v].push_back(make_pair(w, u));
    }

    cin >> first >> last;

    shortestPath();
}