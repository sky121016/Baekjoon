// 2357

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int mushroom[11];
int sum;
int minDiff;
int ans;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i<10; i++){
        cin >> mushroom[i];
    }
    
    int tempDiff = 0;
    minDiff = 100;

    
    for(int i = 0; i<10; i++){
        sum += mushroom[i];
        tempDiff = abs(100 - sum);

        if (minDiff >= tempDiff){
            minDiff = tempDiff;
            ans = sum;
        }else{
            break;
        }
    }

    cout << ans;
}




