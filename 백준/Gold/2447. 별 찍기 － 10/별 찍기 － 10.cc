// 2447
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int N;
bool map[6600][6600];
bool ans[3][3] = {
    {true, true, true},
    {true, false, true},
    {true, true, true},
};

void star(int y, int x, int n){
    if(n == 3){
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                map[y + i][x + j] = ans[i][j];
            }
        }
        return;
    }else{
        star(y, x, n / 3);
        star(y, x + n / 3, n / 3);
        star(y, x + 2 * (n / 3), n / 3);
        star(y + n / 3, x, n / 3);
        star(y + n / 3, x + 2 * (n / 3), n / 3);
        star(y + 2 * (n / 3), x, n / 3);
        star(y + 2 * (n / 3), x + n / 3, n / 3);
        star(y + 2 * (n / 3), x + 2 * (n / 3), n / 3);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    star(0, 0, N);

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(map[i][j]){
                cout<<'*';
            }else{
                cout<<' ';
            }
        }
        cout << "\n";
    }
}

