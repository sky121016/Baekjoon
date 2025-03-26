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

int n;
string s;
map<string, int> file;
int pos;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> s;
        pos = 0;
        for(int j = 0; j<s.length(); j++){
            if(s[j] == '.'){
                pos = j;
            }
        }
        string f = s.substr(pos + 1);

        if(file.find(f) == file.end()){
            file.insert({f, 1});
        }else{
            file.find(f)->second++;
        }
    }

    for(auto iter = file.begin(); iter!=file.end(); ++iter){
        cout << iter->first << " " << iter->second << "\n";
    }
}


