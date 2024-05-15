// 2463
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

int n;
int m;
long long cost;
long long total;
int mod = 1000000000;

int u, v, w;

priority_queue< pair < int, pair < int, int> > > pq;        // < w, < u, v >
int p[101010];
int unionSize[101010];

void createSet(int x){
    p[x] = x;
}

int findSet(int x){
    if(p[x] == x){
        return p[x];
    }
    return p[x] = findSet(p[x]);
}

void makeUnion(int u, int v){
    u = findSet(u);
    v = findSet(v);
    unionSize[u] += unionSize[v];
    p[v] = u;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i<m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        pq.push(make_pair(w, make_pair(x, y)));
        cost += w;
    }

    // init
    for(int i = 1; i<=n; i++){
        createSet(i);
        unionSize[i] = 1;
    }

    for(int i = 0; i<m; i++){
        w = pq.top().first;
        u = pq.top().second.first;
        v = pq.top().second.second;
        pq.pop();

        u = findSet(u);
        v = findSet(v);

        if(u != v){
            long long temp = ((1L * unionSize[u] * unionSize[v]) % mod) * cost;
            total += temp % mod;
            total %= mod;
            makeUnion(u, v);
        }

        cost -= w;
    }

    cout << total % mod;
}

