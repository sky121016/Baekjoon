// 5904
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

long long n;
string moo = "moo";

void S(int num, int k, int len){
    int nl = 2 * len + k + 3;
    if(num<=3){
        cout << moo[num - 1];
        return;
    }

    if (nl < num){
        S(num, k+1, nl);
    }else{
        if(num > len && num <= len+k+3){
            if(num == len + 1){
                cout<<"m\n";
            }else{
                cout<<"o\n";
            }
        }else{
            S(num - (len + k + 3), 1, 3);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    S(n, 1, 3);
}
