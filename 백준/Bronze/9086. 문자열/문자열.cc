#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>

using namespace std;

int t;
string str[11];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for(int i = 0; i<t; i++){
        cin >> str[i];
        cout << str[i][0] << str[i][str[i].length() - 1] << "\n";
    }
}
