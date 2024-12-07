#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n;
char c;
int m;
int cnt;
int ans;
float half;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    half = float(m) / 2;
    for(int i = 0; i<n; i++){
        cnt = 0;
        for(int j = 0; j<m; j++){
            cin >> c;
            if(c == 'O'){
                cnt++;
            }
        }



        if(cnt >= half){
            ans ++;
        }
    }

    cout << ans;
}
