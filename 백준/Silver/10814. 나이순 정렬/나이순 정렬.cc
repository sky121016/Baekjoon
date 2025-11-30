// 1110
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int n;
int ans;
vector<pair<int, string>> member;
int x;

void input(){
    cin >> n;

    int age;
    string name;
    for (int i = 0; i < n; i++){
        cin >> age >> name;
        member.push_back(make_pair(age, name));
    }
}

void output(){
    for (int i = 0; i < n; i++){
        cout << member[i].first << " " << member[i].second << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    stable_sort(member.begin(), member.end(),
        [](const pair<int, string> &a, const pair<int, string> &b)
        {
            return a.first < b.first;
        }
    );

    output();
}
