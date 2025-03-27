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
int coin[4] = {25, 10, 5, 1};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t > 0){
        int cnt[4];

        for(int i = 0; i<4; i++){
            cnt[i] = 0;
        }

        cin >> n;

        int index = 0;
    
        while(n > 0){
            if(n - coin[index] >= 0){
                n -= coin[index];
                cnt[index] ++;
            }else{
                index++;
            }
        }
    
        for(int i = 0; i<4; i++){
            cout<<cnt[i]<<" ";
        }
        cout<<"\n";

        t--;
    }

}

