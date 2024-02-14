// 1339
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int value[27];
int n;
string s[11];
int sum;
int t[10] = {1000000000,100000000,10000000,1000000,100000,10000,1000,100,10,1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> s[i];
    }


    for(int i = 0; i<n; i++){
        for (int j = 0; j < s[i].length(); j++){
            value[s[i][j] - 'A'] += t[10 - s[i].length() + j];
        }
    }

    sort(value, value + 27);
  
    for(int i = 0; i<10; i++){
        sum += value[26-i] * (9-i);
    }
    cout << sum;
}
