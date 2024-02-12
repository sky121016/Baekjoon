// 11399
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int p[1001];
int sum;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> p[i];
    }

    sort(p, p + n);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            sum += p[j];
        }
    }

    cout << sum;
}
