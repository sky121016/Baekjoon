// 11399
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

string s;
vector<char> S;
string t;
vector<char> T;
char temp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    cin >> t;
    for(int i = 0; i<s.length(); i++){
        S.push_back(s[i]);
    }

    for(int i = 0; i<t.length(); i++){
        T.push_back(t[i]);
    }

    char Back;

    int cnt = T.size() - s.length();
    while(cnt > 0){
        Back = T.back();
        if(Back == 'A'){
            T.pop_back();
            
        }else if(Back == 'B'){
            T.pop_back();
            for(int i = 0; i<T.size()/2; i++){
                temp = T[i];
                T[i]= T[T.size()-1-i];

                T[T.size()-1-i] = temp;
            }
        }
        cnt--;
    }



    int ans = 1;
    if(T.size() == s.length()){
        for(int i = 0; i<T.size(); i++){
            if(T[i]!=s[i]){
                ans = 0;
                break;
            }
        }
    }else{
        ans = 0;
    }

    cout<<ans;



}

