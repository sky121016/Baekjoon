// 2357

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
#include<map>
using namespace std;

map<string, int> names;
vector<string> both;

int n, m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i< n + m; i++){
        string str;
        cin >> str;

        names[str] ++ ;

        if(names[str] == 2){
            both.push_back(str);
        }

    }

    sort(both.begin(), both.end());

    cout << both.size() << "\n";

    for(auto name:both){
        cout << name << "\n";
    }

}