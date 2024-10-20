// 17265
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n;
int a, b;

int score[3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    score[0] = 100;
    score[1] = 100;

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> a >> b;

        if (a > b){
            score[1] -= a;
        }else if(a < b){
            score[0] -= b;
        }
    }

    cout << score[0] << "\n"
         << score[1];
}
