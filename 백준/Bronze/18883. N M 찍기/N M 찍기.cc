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

int n,m ;
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    cnt = 1;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << cnt;
            cnt++;
            if(j != m-1){
                cout<<" ";
            }
        }
        cout<<"\n";
    }
}

