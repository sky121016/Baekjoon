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

int s;
int t;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int temp;
    for(int i = 0; i<4; i++){
        cin >> temp;
        s += temp;
    }
    for(int i = 0; i<4; i++){
        cin >> temp;
        t += temp;
    }

    if(s >= t){
        cout<<s;
    }else {
        cout << t;
    }

}

