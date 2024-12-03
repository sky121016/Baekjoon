
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <map>
#include <set>

using namespace std;

int a, b;
int c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;

    cin >> c;

    if(2 * c <= a+b){
        cout << a + b - 2 * c;
    }else{
        cout << a + b;
    }
}
