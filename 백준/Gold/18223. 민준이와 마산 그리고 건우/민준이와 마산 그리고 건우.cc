#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

int v, e;
int p;
int dis[5001];
int disP[5001];
int a, b, c;
int INF = 999999999;
vector<pair<int, int> > adj[5001];


priority_queue<pair<int, int> > pq;

void shortestPath(){
    pq.push(make_pair(0, 1));

    int curr;
    int cost;

    while(!pq.empty()){
        cost = pq.top().first;
        curr = pq.top().second;
        pq.pop();

        for(int i = 0; i<adj[curr].size(); i++){
            int next = adj[curr][i].first;
            int nCost = adj[curr][i].second;

            if(dis[next] > dis[curr] + nCost){
                dis[next] = dis[curr] + nCost;
                pq.push(make_pair(dis[next], next));
            }
        }
    }

}   

void shortestPathFromP(){
    pq.push(make_pair(0, p));

    int curr;
    int cost;

    while(!pq.empty()){
        cost = pq.top().first;
        curr = pq.top().second;
        pq.pop();

        for(int i = 0; i<adj[curr].size(); i++){
            int next = adj[curr][i].first;
            int nCost = adj[curr][i].second;

            if(disP[next] > disP[curr] + nCost){
                disP[next] = disP[curr] + nCost;
                pq.push(make_pair(disP[next], next));
            }
        }
    }

}   


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e >> p;

    for(int i = 1; i<=v; i++){
        dis[i] = INF;
        disP[i] = INF;
    }
    dis[1] = 0;
    disP[p] = 0;

    for(int i = 0; i<e; i++){
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }


    shortestPath();
    shortestPathFromP();


    if(dis[v] == dis[p] + disP[v]){
        cout<<"SAVE HIM";
    }else{
        cout<<"GOOD BYE";
    }
}