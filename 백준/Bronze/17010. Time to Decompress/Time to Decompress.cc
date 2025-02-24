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

int t;
int n;
char s;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t>0){
        cin >> n >> s;

        for(int i = 0; i<n; i++){
            cout << s;
        }
        cout << "\n";
        
        t--;
    }
}
