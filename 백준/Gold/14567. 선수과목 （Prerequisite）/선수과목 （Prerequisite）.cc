#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

using namespace std;


int n, m;
int a, b;
vector<int> out [1010];
int cnt[1010];
int semester[1010];
bool visited[1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i<m; i++){
        cin >> a >> b;
        out[a].push_back(b);
        cnt[b]++;
    }

    for(int i = 1; i<=n; i++){
        semester[i] = 1;
    }

    for(int t = 0; t<n; t++){
        for(int i = 1; i<=n; i++){
            if(cnt[i] == 0 && !visited[i]){
                visited[i] = true;
                for(int j = 0; j<out[i].size(); j++){
                    cnt[out[i][j]]--;
                    semester[out[i][j]] = max(semester[i] + 1, semester[out[i][j]]);
                }
            }
        }
    }

    for(int i = 1; i<=n; i++){
        cout<<semester[i]<<" ";
    }
}

