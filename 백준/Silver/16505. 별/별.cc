#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int N;
char map[1500][1500];


void star(int y, int x, int n){
    int last = pow(2, n-1);
    if(n == 0){
        map[y][x] = '*';
        return;
    }else{
        star(y, x, n -1);
        star(y, x + last, n -1);
        star(y + last, x, n -1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int last = pow(2, N);
    for(int i = 0; i<last; i++){
        for(int j = 0; j<last; j++){
            map[i][j] = ' ';
        }
    }
    star(0, 0, N);

    for (int i = 0; i < last; i++){
        for(int j = 0; j < last-i; j++){
            cout << map[i][j];
        }
        cout<<"\n";
    }
}


