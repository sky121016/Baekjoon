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

int n;
int a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> a >> b;
        if(a>=b){
            cout << "MMM BRAINS\n";
        }else{
            cout << "NO BRAINS\n";
        }
    }
}

