// 4673
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;


bool arr[10001];

void d(int num){
    int sum = 0;
    sum = num;


    while(num >= 1){
        sum += num % 10;
        num /= 10;
    }

    if(sum < 10001){
        arr[sum] = true;
        d(sum);
    }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 1; i<10001; i++){
        if(!arr[i]){
            d(i);
        }
    }

    for(int i = 1; i<10001; i++){
        if(!arr[i]){
            cout << i << "\n";
        }
    }
}


