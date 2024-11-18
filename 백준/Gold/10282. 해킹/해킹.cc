#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

int n, d, c;
int a, b, s;
vector<pair<int, int> > adj[10001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int dis[10001];

int t;

void shortestPath(){

    pq.push(make_pair(0, c));
    dis[c] = 0;

    int curr;
    int cost;

    int next;
    int nextDis;

    while(!pq.empty()){
        curr = pq.top().second;
        cost = pq.top().first;
        pq.pop();


        if(dis[curr] < cost){continue;}

        for(int i = 0; i<adj[curr].size(); i++){
            next = adj[curr][i].second;
            nextDis = adj[curr][i].first;
            
            if(nextDis + cost < dis[next]){
                dis[next] = nextDis + cost;
                pq.push(make_pair(dis[next], next));
            }
        }
    }

}

void init(){
    for(int i = 0; i<=n; i++){
        dis[i] = 999999999;
    }

    
}


void reset(){
    for(int i = 0; i<=n; i++){
        adj[i].clear();
    }

    while(!pq.empty()){
        pq.pop();
    }

}

void getResult(){
    int cnt = 0;
    int ans = 0;

    for(int i = 1; i<=n; i++){
        if(dis[i] != 999999999){
            cnt++;
            if(dis[i] > ans){
                ans = dis[i];
            }
        }

    }


    cout << cnt << " " << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t > 0){
        cin >> n >> d >> c;
        init();

        for(int i = 0; i<d; i++){
            cin >> a >> b >> s;
            adj[b].push_back(make_pair(s, a));
        }

        shortestPath();
        getResult();
        reset();

        t--;
    }
}