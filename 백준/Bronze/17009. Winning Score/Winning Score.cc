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

int a[3];
int b[3];
int apple;
int banana;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];

    apple = a[0] * 3 + a[1] * 2 + a[2];
    banana = b[0] * 3 + b[1] * 2 + b[2];

    if(apple > banana){
        cout << "A";
    }
    else if(apple < banana){
        cout << "B";
    }else{
        cout << "T";
    }
}