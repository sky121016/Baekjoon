// 1074
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, r, c;
int v = 1;
int ans;

void Z(int n){

    if(n == 1){
        return ;
    }

    if(r < n/2 && c < n/2){       // 왼 위
        ans = ans + 0;
        Z(n / 2);
    }else if(r < n/2 && c>=n/2){    // 오 위
        c -= n / 2;
        ans = ans + (n/2) * (n/2);
        Z(n / 2);
    }
    else if (r >= n / 2 && c < n / 2){    // 왼 아
        r -= n / 2;
        ans = ans + (n/2) * (n/2) * 2;
        Z(n / 2);
    }
    else if (r >= n / 2 && c >= n / 2){
        r -= n / 2;
        c -= n / 2;
        ans = ans + (n/2) * (n/2) * 3;              // 오 아
        Z(n / 2);
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r >> c;

    for(int i = 0; i<N; i++){
        v *= 2;
    }

    Z(v);

    cout << ans;

}
