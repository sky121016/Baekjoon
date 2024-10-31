// 2357

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int l, p;
int n;
int people;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> l >> p;

    people = l * p;

    for(int i = 0; i<5; i++){
        cin >> n;
        cout << n - people << " ";
    }
}
