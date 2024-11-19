#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>

using namespace std;


int n, m, r;
int dis[101][101];
int a, b, l;
int INF = 99999999;
int item[101];
int maxItem[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }

    for(int i = 1; i<=n; i++){
        cin >> item[i];
    }

    for(int i = 0; i<r; i++){
        cin >> a >> b >> l;
        dis[a][b] = l;
        dis[b][a] = l;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(dis[i][j] <= m){
                maxItem[i] += item[j];
            }
        }
    }


    cout << *max_element(maxItem, maxItem + n);
}