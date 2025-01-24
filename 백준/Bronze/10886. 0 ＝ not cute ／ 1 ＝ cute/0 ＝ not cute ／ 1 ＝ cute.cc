#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n;
int cnt;
int zcnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    int a;
    for(int i = 0; i<n; i++){
        cin >> a;
        if(a == 1){
            cnt++;
        }else{
            zcnt++;
        }
    }


    if(cnt > zcnt){
        cout<<"Junhee is cute!";
    }else{
        cout<<"Junhee is not cute!";
    }


}
