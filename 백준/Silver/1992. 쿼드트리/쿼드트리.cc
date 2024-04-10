// 1992
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

int N;
char map[65][65];
char first;


bool check(int y, int x, int n){
    first = map[y][x];


    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(map[y+i][x+j] != first){
                return false;
            }
        }
    }

    return true;
}

void quadtree(int y, int x, int n){

    if(check(y, x, n)){
        cout << map[y][x];
        return;
    }else{
        cout<<"(";
        quadtree(y, x, n / 2);
        quadtree(y, x + n / 2, n / 2);
        quadtree(y + n / 2, x, n / 2);
        quadtree(y + n / 2, x + n / 2, n / 2);
        cout<<")";
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> map[i][j];
        }
    }

    quadtree(0, 0, N);
}

