#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int p;
int t;
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> p;

    while(p > 0){
        int height[21];
        cnt = 0;

        cin >> t;

        for(int i = 0; i<20; i++){
            cin >> height[i];
        }


        for(int i = 0; i<20; i++){
            for(int j = i; j<20; j++){
                if(height[j] < height[i]){
                    cnt++;
                }
            }
        }

        cout << t << " " << cnt << "\n";
        p--;
    }
}
