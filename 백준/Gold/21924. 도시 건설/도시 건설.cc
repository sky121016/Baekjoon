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

long n;
long m;

priority_queue<pair<long, pair<long, long>>, vector<pair<long, pair<long, long>>>, greater<pair<long, pair<long, long>>>> cost;
vector<long> parent;
long line;

long find(long v){
    if(parent[v] == v){
        return v;
    }

    return parent[v] = find(parent[v]);
}

long ans;
long total;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    long a, b, c;
    for(long i = 0; i<m; i++){
        cin >> a >> b >> c;
        total += c;
        cost.push(make_pair(c, make_pair(a, b)));
    }

    parent.push_back(0);
    for(long i = 1; i<=n; i++){
        parent.push_back(i);
    }

    while(!cost.empty()){
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
            line++;
        }

    }

    for(int i = 2; i<=n; i++){
        if(find(1) != find(i)){
            cout << -1;
            return 0;
        }
    }

    cout << total - ans;
}

