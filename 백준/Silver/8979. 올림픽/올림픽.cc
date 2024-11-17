#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int n, k;
int medal[1001][3];
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    int country;
    int a, b, c;
    for(int i = 1; i<=n; i++){
        cin >> country >> a >> b >> c;
        medal[country][0] = a;
        medal[country][1] = b;
        medal[country][2] = c;
    }


    ans = 1;

    for(int i = 1; i<=n; i++){
        if(i == k){
            continue;
        }

        if(medal[i][0] > medal[k][0]){
            ans++;
        }else if(medal[i][0] == medal[k][0]){
            if(medal[i][1] > medal[k][1]){
                ans++;
            }else if(medal[i][1] == medal[k][1]){
                if(medal[i][2] > medal[k][2]){
                    ans++;
                }
            }
        }
    }

    cout << ans;
}
