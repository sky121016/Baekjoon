#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dis[51][51];
int INF = 99999999;
int cnt;

int solution(int N, vector<vector<int> > road, int K) {
    
    
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }
    
    for(int i = 0; i<road.size(); i++){
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        
        dis[a][b] = min(dis[a][b], c);
        dis[b][a] = min(dis[b][a], c);
    }
    
    for(int k = 1; k<=N; k++){
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=N; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    

    for(int i = 1; i<=N; i++){
        if(dis[1][i] <= K){
            cnt++;
        }
    }
    
    return cnt;
}