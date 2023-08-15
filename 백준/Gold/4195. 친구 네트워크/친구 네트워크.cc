// 4195 친구 네트워크
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int T;
int F;
map<string, string> m;
map<string, int> cnt;

string find(string a){                // 루트 찾기
    if(a == m[a]){
        return a;
    }

    return m[a] = find(m[a]);
}

void add(string a, string b){
    a = find(a);
    b = find(b);

    if(a != b){
        m[b] = a;
        cnt[a] += cnt[b];            // 네트워크 수 늘리기
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    string a, b;


    
    for(int i = 0; i<T; i++){
        cin >> F;
        for(int j = 0; j<F; j++){
            cin >> a >> b;
            if(m.find(a)==m.end()){        // 처음이면
                m[a] = a;
                cnt[a] = 1;
            }
            if(m.find(b)==m.end()){        // 처음이면
                m[b] = b;
                cnt[b] = 1;
            }
            
            add(a, b);
            
            cout<<cnt[find(a)]<<"\n";
        }

        m.clear();
        cnt.clear();

    }
}

