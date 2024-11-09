// 2357

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int temp;
    for(int i = 0; i<10; i++){
        cin >> temp;
        cnt += temp;
        cnt = cnt % 4;
    }

    if(cnt == 0){
        cout<<"N";
    }else if(cnt == 1){
        cout<<"E";
    }else if(cnt == 2){
        cout<<"S";
    }else{
        cout<<"W";
    }


}