#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

int c;
int score[11][11];
bool visited[11];

int ans;

void init(){
    for(int i = 0; i<11; i++){
        for(int j = 0; j<11; j++){
            cin >> score[i][j];
        }
    }

    for(int i = 0; i<11; i++){
        visited[i] = false;
    }

    ans = 0;
}

void dfs(int cnt, int sum){
    if(cnt == 11){
        ans = max(ans, sum);
        return;
    }

    for(int i = 0; i<11; i++){
        if(!visited[i] && score[i][cnt] != 0){
            visited[i] = true;
            dfs(cnt + 1, sum + score[i][cnt]);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> c;

    while(c > 0){
        init();

        dfs(0, 0);

        c--;
        cout << ans<<"\n";
    }

}