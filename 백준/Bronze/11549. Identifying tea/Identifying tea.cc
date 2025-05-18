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

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int a;
    int cnt = 0;
    for(int i = 0; i<5; i++){
        cin >> a;
        if(a == n){
            cnt++;
        }
    }

    cout << cnt;
}

