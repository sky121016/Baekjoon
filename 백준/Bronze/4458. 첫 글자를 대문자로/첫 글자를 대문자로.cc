// 17265
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n;
string s;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin.ignore();


    for(int i = 0; i<n; i++){
        getline(cin, s);
        if(s[0] >= 'a'){
            s[0] = s[0] - 32;
        }
        cout << s << "\n";
    }
}

