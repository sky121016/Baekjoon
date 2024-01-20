// 14719
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[501][501];
int block;
int w,h;
int cnt;
int temp;
bool canCount;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;

    for(int i = 0; i<w; i++){
        cin >> block;
        for(int j = 0; j<block; j++){
            map[h-j-1][i] = 1;
        }
    }


    for(int i = h-1; i>=0; i--){
        for(int j = 0; j<w; j++){
            if(canCount && map[i][j] == 0){
                temp++;
            }else if(map[i][j] == 1){
                canCount = true;
                cnt += temp;
                temp = 0;
            }
        }
        temp = 0;
        canCount = false;
    }

    cout << cnt;
}
