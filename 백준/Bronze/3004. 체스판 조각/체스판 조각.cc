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

float n;
int a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    if(int(n) % 2 == 0){
        a = round((n + 1) / 2);
        b = round(((n + 1) / 2));
        cout <<  a * b;
    }else{
        a = round(n / 2);
        b = round((n / 2) + 1);
        cout << a * b;
    }

}