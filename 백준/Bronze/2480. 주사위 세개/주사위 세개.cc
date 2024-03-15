// 2480
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int a[4];
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a[1] >> a[2] >> a[3];


    if(a[1] == a[2]){
        if(a[2] == a[3]){
            ans = a[1] * 1000 + 10000;
        }else{
            ans = a[1] * 100 + 1000;
        }
    }else{
        if(a[2] == a[3]){
            ans = a[2] * 100 + 1000;
        }else if(a[1] == a[3]){
            ans = a[1] * 100 + 1000;
        }else{
            ans = *max_element(a, a + 4) * 100;
        }
    }

    cout << ans;
}


