// 14921
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;


int n;
int a[101010];
int sum;
int ans = 200000001;
int s, e;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    s = 0;
    e = n-1;

    while(s != e){
        sum = a[s] + a[e];

        if(sum > 0){
            e--;
        }else{
            s++;
        }

        if(abs(ans) > abs(sum)){
            ans = sum;
        }
    }

    cout << ans;
}


