// 2250 트리
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int map[130][130];
bool flag = true;
int cnt[2];
int first;

void paper(int n, int y, int x){
    if(n == 1){
        if(map[y][x] == 1){
            cnt[1]++;
        }else{
            cnt[0]++;
        }
        return;
    }else{
        flag = true;
        first = map[y][x];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(map[y+i][x+j] != first){
                    flag = false;
                    break;
                }
            }
        }
        if(flag == false){
            paper(n / 2, y, x);
            paper(n / 2, y, x + n / 2);
            paper(n / 2, y + n / 2, x);
            paper(n / 2, y + n / 2, x + n / 2);
        }else{
            cnt[first]++;
        }
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

    paper(N, 0, 0);

    cout << cnt[0] << "\n" << cnt[1];
}
