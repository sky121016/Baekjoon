// 1238
#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>


using namespace std;

int n, m, x;

int dist[1001];
vector< pair<int, int> > adj[1001];
priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >  pq;
int ans[1001];


int shortestPath(int idx, int dest){
    dist[idx] = 0;

    pq.push(make_pair(dist[idx], idx));

    pair<int, int> v;
    int vIdx, vWei;

    while(!pq.empty()){
        v = pq.top();
        pq.pop();

        vWei = v.first;
        vIdx = v.second;

        for(int i = 0; i<adj[vIdx].size(); i++){
            pair<int, int> n = adj[vIdx][i];

            int nWei = adj[vIdx][i].first;
            int nIdx = adj[vIdx][i].second;


            if(dist[vIdx] + nWei < dist[nIdx]){
                dist[nIdx] = dist[vIdx] + nWei;
                pq.push(make_pair(dist[nIdx], nIdx));
            }
        }
    }

    return dist[dest];
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> x;

    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(c, b));
    }



    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            dist[j] = 1010101010;
        }
        ans[i] = shortestPath(i, x);
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            dist[j] = 10101010;
        }
        ans[i] += shortestPath(x, i);
    }

    cout << *max_element(ans, ans + n+1);
}



