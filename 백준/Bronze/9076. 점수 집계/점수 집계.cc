// 17265
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;


int t;

int Max;
int Min;

int a[5];
int sum;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for(int i = 0; i<t; i++){
        sum = 0;
        for(int j = 0; j<5; j++){
            cin >> a[j];
        }

        sort(a, a+5);
        sum = a[1] + a[2] + a[3];

        if(a[3]- a[1] >= 4){
            cout<<"KIN\n";
        }else{
            cout << sum << "\n";
        }
    }
}
