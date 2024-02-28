// 11758
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

double X1, X2, X3, Y1, Y2, Y3;
int ans;
int temp;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> X1 >> Y1;
    cin >> X2 >> Y2;
    cin >> X3 >> Y3;

    temp = X1 * Y2 + X2 * Y3 + X3 * Y1;
    temp = temp - Y1 * X2 - Y2 * X3 - Y3 * X1;

    if(temp > 0){
        ans = 1;
    }else if(temp < 0){
        ans = -1;
    }else{
        ans = 0;
    }


    cout << ans;
}


