// 1937
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

priority_queue<pair<int, pair<int, int> > > pq;
int n;
int map[501][501];
int dp[501][501];
int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

int M;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int temp;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> temp;
            map[i][j] = temp;
            pq.push(make_pair(temp, make_pair(i, j)));
        }
    }

    int y, x;
    int v;
    for(int i = 0; i < n * n; i++){
        v = pq.top().first;
        y = pq.top().second.first;
        x = pq.top().second.second;


        int ny, nx;

        for(int j = 0; j < 4; j++){
            ny = y + dir[j][0];
            nx = x + dir[j][1];
            

            if(map[ny][nx] > v){
                dp[y][x] = max(dp[ny][nx] + 1, dp[y][x]);

                if(M < dp[y][x]){
                    M = dp[y][x];
                }
            }
        }

        pq.pop();
    }

    cout << M+1;
}

