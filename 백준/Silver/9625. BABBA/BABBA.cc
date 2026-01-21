// 11053
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int k;
int a[46];
int b[46];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;

    a[0] = 1;
    b[0] = 0;

    for(int i = 1; i<=k; i++){
        a[i] = b[i-1];
        b[i] = b[i-1]+a[i-1];
    }

    cout << a[k] << " " << b[k];
}