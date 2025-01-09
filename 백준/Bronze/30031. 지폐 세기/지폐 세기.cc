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
int a, b;
int cnt;

int getCash(int m){
    if(m == 136){
        return 1000;
    }else if(m == 142){
        return 5000;
    }else if(m == 148){
        return 10000;
    }else{
        return 50000;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i <n; i++){
        cin >> a >> b;
        cnt += getCash(a);
    }

    cout << cnt;
}