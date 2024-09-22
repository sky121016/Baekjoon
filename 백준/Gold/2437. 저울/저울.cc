// 13398
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;


int n;
int w[1010];
int sum;
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> w[i];
    }

    sort(w, w+n);

    sum = 1;

    for(int i = 0; i<n; i++){
        if(w[i] > sum){
            break;
        }

        sum += w[i];
    }

    cout << sum;
}

