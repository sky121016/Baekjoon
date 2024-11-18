#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>

using namespace std;




int t, n;
int ans;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t > 0){
        cin >> n;

        string a, b;
        map<string, int> m;
        for(int i = 0; i<n; i++){
            cin >> a >> b;
            if(m.find(b) == m.end()){
                m.insert({b, 2});
            }else{
                m[b]++;
            }
        }

        ans = 1;

        for(auto iter = m.begin(); iter!=m.end(); ++iter){
            ans = ans * iter->second;
        }

        cout << ans - 1 << "\n";

        t--;
    }
}
