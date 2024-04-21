#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>

using namespace std;

string s;
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    ans = 1;

    for(int i = 0; i<s.length()/2; i++){
        if(s[i] != s[s.length()-i-1]){
            ans = 0;
            cout << ans;
            return 0;
        }
    }

    cout << ans;
}

