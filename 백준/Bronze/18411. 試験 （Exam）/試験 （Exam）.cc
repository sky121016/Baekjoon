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

vector<int> a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int temp;
    for(int i = 0; i<3; i++){
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    cout << a[2] + a[1];
}

