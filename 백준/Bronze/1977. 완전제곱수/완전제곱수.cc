#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int m, n;

bool a[10010];
int cnt;
bool first;
int minV;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 1; i<=100; i++){
        a[i * i] = true;
    }

    cin >> m >> n;

    for(int i = m; i<=n; i++){
        if(a[i]){
            if(!first){
                minV = i;
                first = true;
            }

            cnt += i;
        }
    }

    if(cnt == 0){
        cout << -1;
        return 0;
    }
    cout << cnt << "\n"
         << minV;
}