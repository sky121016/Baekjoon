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


int a, b;
int t;

int getGcd(int x, int y){
    if(y == 0){
        return x;
    }

    return getGcd(y, x % y);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>t;

    while(t>0){
        cin >> a >> b;
        int bigger = max(a, b);
        int smaller = min(a, b);
        int gcd = getGcd(bigger, smaller);

        int lcm = (bigger * smaller) / gcd;

        cout << lcm << " " << gcd << "\n";

        t--;
    }
}