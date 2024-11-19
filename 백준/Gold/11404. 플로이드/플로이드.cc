#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

int n;
int m;
int a, b, c;

int dis[101][101];

int INF = 99999999;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }

    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b],c);
    }

    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(dis[i][j] == INF){
                cout << 0 << " ";
            }else{
                cout << dis[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

