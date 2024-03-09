// 16395 파스칼
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int map[6600][6600];

int pat[3][3] = {
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1},
};

void star(int n, int y, int x){
    if(n == 3){
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                map[y + i][x + j] = pat[i][j];
            }
        }
        return;
    }
    
    star(n / 3, y, x);
    star(n / 3, y, x + n / 3);
    star(n / 3, y, x + 2 * (n / 3));
    star(n / 3, y+n / 3, x);
    star(n / 3, y + n / 3, x + 2 * (n / 3));
    star(n / 3, y + 2*(n / 3), x);
    star(n / 3, y + 2 * (n / 3), x + n / 3);
    star(n / 3, y + 2 * (n / 3), x + 2 * (n / 3));
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    star(N, 0, 0);

    for(int i =0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(map[i][j] == 1){
                cout<<"*";
            }else{
                cout<<' ';
            }
        }
        cout<<"\n";
    }
}
