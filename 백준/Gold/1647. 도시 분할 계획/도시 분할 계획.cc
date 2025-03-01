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

int maxC;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int a, b, c;
    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        cost.push(make_pair(c, make_pair(a, b)));
    }

    parent.push_back(0);
    for(int i = 1; i<=n; i++){
        parent.push_back(i);
    }

    while(true){
        if(line == n-1){
            break;
        }


        a = cost.top().second.first;
        b = cost.top().second.second;
        c = cost.top().first;

        cost.pop();

        a = find(a);
        b = find(b);

        if(a == b){
            continue;
        }else{
            parent[a] = b;
            ans += c;
            if(maxC < c){
                maxC = c;
            }
            line++;
        }



    }

    ans -= maxC;

    cout << ans;
}

