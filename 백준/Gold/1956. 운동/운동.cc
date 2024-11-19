#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

int v, e;
int a, b, c;
int dis[401][401];

int INF = 99999999;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e;

    for(int i = 1; i<=v; i++){
        for(int j = 1; j<=v; j++){
            dis[i][j] = INF;
        }
    }

    for(int i = 0; i<e; i++){
        cin >> a >> b >> c;
        dis[a][b] = c;
    }

    for(int k = 1; k<=v; k++){
        for(int i = 1; i<=v; i++){
            for(int j = 1; j<=v; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    int minDis = INF;
    for(int i = 1; i<=v; i++){
        if(dis[i][i] < minDis){
            minDis = dis[i][i];
        }
    }

    if(minDis == INF){
        cout << -1;
    }else{
        cout << minDis;
    }


}


