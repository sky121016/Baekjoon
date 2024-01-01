// 1439
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string temp;
int cnt[2];

vector<char> s;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> temp;

    s.push_back('a');

    for(int i = 1; i<=temp.length(); i++){
        s.push_back(temp[i-1]);
        if(s[i] != s[i-1]){
            cnt[int(s[i]) - 48]++;
        }
    }

    cout << min(cnt[0], cnt[1]);
}

