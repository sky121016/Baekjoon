// 2467
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int n;
int arr[101010];
int l, r;
int ans = 2000000001;
int a, b;
int sum;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    l = 0;
    r = n - 1;

    while(l < r){
        sum = arr[l] + arr[r];
        if(abs(sum) < abs(ans)){
            ans = sum;
            a = arr[l];
            b = arr[r];
        }

        if(sum < 0){
            l++;
        }else if(sum > 0){
            r--;
        }else{
            cout << a << " " << b;
            return 0;
        }
    }

    cout << a << " " << b;
}
