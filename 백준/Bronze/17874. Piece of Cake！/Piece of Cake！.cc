#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int n, h, v;
int bigH, bigV;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> h >> v;


    if(h > n - h){
        bigH = h;
    }else{
        bigH = n - h;
    }

    if (v > n - v){
        bigV = v;
    }else{
        bigV = n - v;
    }

    cout << bigH * bigV * 4;
}
