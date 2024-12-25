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

int n;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i<n+2; i++){
        cout<<"@";
    }
    cout<<"\n";

    for(int i = 0; i<n; i++){
        cout<<"@";
        for(int j = 0; j<n; j++){
            cout<<" ";
        }
        cout<<"@\n";
    }

    for(int i = 0; i<n+2; i++){
        cout<<"@";
    }

}
