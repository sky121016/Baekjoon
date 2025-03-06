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
int m;
int p, q;
int t;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> cost;
vector<int> parent;

int line;

int find(int v){
    if(parent[v] == v){
        return v;
    }

    return parent[v] = find(parent[v]);
}

int ans;
int total;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        cin >> m >> n;
        ans = 0;
        total = 0;
        line = 0;
        parent.clear();

        while(!cost.empty()){
            cost.pop();
        }

        if(m == 0 && n == 0){
            break;
        }

        parent.push_back(0);
        for(int i = 1; i<=m; i++){
            parent.push_back(i);
        }

        
        int a, b, c;
        
        for(int i = 0; i<n; i++){
            cin >> a >> b >> c;
            total += c;
            cost.push(make_pair(c, make_pair(a, b)));
        }



        while(!cost.empty()){
            if(line == m-1){
                break;
            }

            a = cost.top().second.first;
            b = cost.top().second.second;
            c = cost.top().first;

            cost.pop();

            int ap = find(a);
            int bp = find(b);

            if(ap != bp){
                parent[ap] = bp;
                line++;
                ans += c;
            }

        }

        cout << total - ans << "\n";
    }
}
