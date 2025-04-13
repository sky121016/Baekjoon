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

int n, k;
int a[51];
int ans;
bool visited[51];

void choose(int sum, int cnt){
    if(sum < 500){
        return;
    }

    if(cnt == n){
        if(sum >= 500){
            ans ++;
        }
        
        return;
    }

    for(int i = 1; i<= n; i++){
        if(!visited[i]){
            visited[i] = true;
            choose(sum-k+a[i], cnt+1);
            visited[i] = false;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    choose(500, 0);

    cout << ans;
}
