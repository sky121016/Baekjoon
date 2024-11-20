#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

int n, k;

int maxCnt;
vector<string> word;
bool visited[27];

int readCnt;


void dfs(int cnt, int idx){
    if(cnt == k){
        int tempCnt = 0;
        for(int i = 0; i < word.size(); i++){
            bool flag = true;
            for(int j = 0; j<word[i].length(); j++){
                if(!visited[word[i][j] - 'a']){
                    flag = false;
                    break;
                }
            }

            if(flag){
                tempCnt++;
            }
        }

        maxCnt = max(maxCnt, tempCnt);
        return;
    }

    for(int i = idx; i<26; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(cnt + 1, i);
            visited[i] = false;
        }
    }
}   

void init(){
    visited['a'-'a'] = true;
    visited['n'-'a'] = true;
    visited['t'-'a'] = true;
    visited['i'-'a'] = true;
    visited['c'-'a'] = true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    string s;
    for(int i = 0; i<n; i++){
        cin >> s;
        word.push_back(s.substr(4, s.length()-8));
    }

    init();

    if(k < 5){
        cout << 0;
        return 0;
    }
    
    dfs(5, 0);

    cout << maxCnt;
}

