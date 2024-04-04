// 2616
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int n, m;
int map[301][301];
int sum[301][301];
int k;
int i,j,x,y;
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int r = 1; r<=n; r++){
        for(int c = 1; c<=m; c++){
            cin >> map[r][c];
        }
    }




    for(int r = 1; r<=n; r++){
        for(int c = 1; c<=m; c++){
            sum[r][c] = sum[r - 1][c] + sum[r][c - 1] + map[r][c] - sum[r - 1][c - 1];
        }
    }

    cin >> k;

    while(k > 0){

        cin >> i >> j >> x >> y;

        ans = sum[x][y] - sum[x][j-1] - sum[i-1][y] + sum[i-1][j-1];

        cout << ans << "\n";
        k--;
    }

}
