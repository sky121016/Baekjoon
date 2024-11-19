#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>

using namespace std;


int n, k;
int s;
int dis[401][401];
int INF = 999999999;

int a, b;

int c, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            dis[i][j] = INF;
        }
    }

    for(int i = 0; i<k; i++){
        cin >> a >> b;
        dis[a][b] = 1;
    }

    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

 
    cin >> s;

    while(s>0){
        cin >> c >> d;
        if(dis[c][d] < INF){
            cout << "-1\n";
        }else if(dis[d][c] < INF){
            cout << "1\n";
        }else{
            cout<<"0\n";
        }

        s--;
    }
}

