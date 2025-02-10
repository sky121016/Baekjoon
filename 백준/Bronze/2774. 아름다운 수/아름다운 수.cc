#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int t;
string s;

bool num[10];
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t > 0){
        cin >> s;

        for(int i = 0; i<s.length(); i++){
            num[s[i]-'0'] = true;
        }

        for(int i = 0; i<10; i++){
            if(num[i]){
                cnt++;
            }
        }

        cout << cnt << "\n";

        cnt = 0;

        for(int i = 0; i<10; i++){
            num[i] = false;
        }

        t--;
    }
}