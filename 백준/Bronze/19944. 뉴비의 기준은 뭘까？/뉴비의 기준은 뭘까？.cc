#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n, m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    if (m == 1 || m == 2){
        cout<<"NEWBIE!";
    }else if(m <= n){
        cout<<"OLDBIE!";
    }else{
        cout<<"TLE!";
    }
}
