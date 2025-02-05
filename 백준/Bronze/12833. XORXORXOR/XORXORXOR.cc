#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;

    if(c % 2 == 0){
        cout << a;
    }else{
        cout << (a ^ b);
    }
}
