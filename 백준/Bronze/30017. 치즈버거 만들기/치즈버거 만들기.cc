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

int a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>a>>b;

    if(a-1 <= b){
        cout << 2 * a - 1;
    }else{
        cout << 2 * b + 1;
    }

}

