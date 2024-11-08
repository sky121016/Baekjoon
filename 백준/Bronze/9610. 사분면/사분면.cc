// 2357

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n;
int cnt[6];

void getLocation(int x, int y){
    if (x > 0){
        if(y > 0){
            cnt[1]++;
        }else if(y < 0){
            cnt[4]++;
        }else{
            cnt[5]++;
        }
    }else if(x < 0){
        if(y > 0){
            cnt[2]++;
        }else if(y < 0){
            cnt[3]++;
        }else{
            cnt[5]++;
        }
    }else{
        cnt[5]++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int x, y;
    for(int i = 0; i<n; i++){
        cin >> x >> y;
        getLocation(x, y);
    }

    cout << "Q1: " << cnt[1] << "\n";
    cout << "Q2: " << cnt[2] << "\n";
    cout << "Q3: " << cnt[3] << "\n";
    cout << "Q4: " << cnt[4] << "\n";
    cout << "AXIS: " << cnt[5] << "\n";

}

