#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

int result[6][3];
int t = 4;
int ans;
vector<pair<int, int> > match;


void dfs(int cnt){
    if(cnt == 15){
        ans = 1;
        return;
    }

    int a = match[cnt].first;
    int b = match[cnt].second;


    // win
    if(result[a][0] > 0 && result[b][2] > 0){
        result[a][0]--;
        result[b][2]--;
        dfs(cnt+1);
        result[a][0]++;
        result[b][2]++;
    }
    // lose
    if(result[a][2] > 0 && result[b][0] > 0){
        result[a][2]--;
        result[b][0]--;
        dfs(cnt+1);
        result[a][2]++;
        result[b][0]++;
    }
    // tie
    if(result[a][1] > 0 && result[b][1] > 0){
        result[a][1]--;
        result[b][1]--;
        dfs(cnt+1);
        result[a][1]++;
        result[b][1]++;
    }


}

int sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(t > 0){
        sum = 0;

        for(int i = 0; i<6; i++){
            for(int j = 0; j<3; j++){
                cin >> result[i][j];
                sum += result[i][j];
            }
        }


        

        for(int i = 0; i<5; i++){
            for(int j = i+1; j<6; j++){
                match.push_back(make_pair(i, j));
            }
        }

        ans = 0;
        dfs(0);

        if(sum != 30){
            ans = 0;
        }


        cout << ans << " ";
        t--;
    }
 
}

