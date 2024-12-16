


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

int n,A,B;
int a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> A >> B;
    a = 1;
    b = 1;

    while (n--){
        a += A;
        b += B;

        if (a < b){
            swap(a, b);
        }else if (a == b){
            b--;
        }
    }
    cout << a << " " << b;

}
