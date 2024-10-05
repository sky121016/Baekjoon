// 17265
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n;
bool s[501][501];

void star(int x, int cnt){
    if(x == 1){
        return;
    }

    for (int i = 0; i < 4 * x - 3; i++){
        s[cnt][cnt + i] = true;
        s[cnt + x * 4 - 2][cnt + i] = true;
    }

    for (int i = 0; i < 4 * x - 1; i++){
        s[i+cnt][cnt] = true;
    }

    for (int i = 2; i < 4 * x - 1; i++){
        s[i + cnt][4 * x - 4 + cnt] = true;
    }

    s[cnt + 2][cnt + 4 * x - 5] = true;

    if(x == 2){
        for(int i = 0; i<3; i++){
            s[cnt+2+i][cnt+2] = true;
        }
    }

    star(x - 1, cnt + 2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    if(n != 1){
        star(n, 0);
    }else{
        cout<<"*";
        return 0;
    }

    for(int i = 0; i<4*n-1; i++){
        for(int j = 0; j<4*n-3; j++){
            if(s[i][j]){
                cout<<"*";
            }else{
                cout<<" ";
            }
            if(i == 1 && j>0){break;}
        }
        cout<<"\n";
    }

}
