#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int> > adj[51];
int INF = 99999999;
int cnt;
int dis[51];

void shortestPath(){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    
    dis[1] = 0;
    pq.push(make_pair(0, 1));
    

    int curr, curr_cost;
    while(!pq.empty()){
        curr_cost = pq.top().first;
        curr = pq.top().second;
        pq.pop();
    
        int next, nCost;
        
        for(int i = 0; i<adj[curr].size(); i++){
            nCost = adj[curr][i].first;
            next = adj[curr][i].second;
            
            if(dis[curr] + nCost < dis[next]){
                dis[next] = curr_cost + nCost;
                pq.push(make_pair(dis[next], next));
            }
        }
        
    }
    
}

int solution(int N, vector<vector<int> > road, int K) {
    
    for(int i = 0; i<road.size(); i++){
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        
        adj[a].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, a));
    }
    
    for(int i = 1; i<= N; i++){
        dis[i] = INF;
    }
    
    
    shortestPath();
    
    for(int i = 1; i<= N; i++){
        if(dis[i] <= K){
            cnt++;
        }
    }
    
    return cnt;
    
    
}