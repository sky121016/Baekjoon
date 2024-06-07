// 11657
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include <climits>

using namespace std;

class Edge{
public:
    int s, e;
    long long w;

    void setEdge(int s, int e, long long w){
        this->s = s;
        this->e = e;
        this->w = w;
    }
};

int n, m;
long long dist[501];
Edge edge[6001];
long long inf = LLONG_MAX;

bool shortest(){
    for (int i = 1; i <= n; i++){
        dist[i] = inf;
    }
    dist[1] = 0;

    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<m; j++){
            int s = edge[j].s;
            int e = edge[j].e;
            long long w = edge[j].w;

            if(dist[s] == inf){
                continue;
            }

            if(dist[e] > dist[s] + w){
                dist[e] = dist[s] + w;
            }
        }
    }


    for(int j = 0; j<m; j++){
        int s = edge[j].s;
        int e = edge[j].e;
        long long w = edge[j].w;


        if(dist[s] == inf){
            continue;
        }

        if(dist[e] > dist[s] + w){
            return false;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int a, b;
    long long c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        edge[i].setEdge(a, b, c);
    }

    if(shortest() == false){
        cout<<"-1";
    }else{
        for(int i = 2; i<=n; i++){
            if(dist[i] == inf){
                cout<<"-1\n";
            }else{
                cout << dist[i] << "\n";
            }
        }
    }
}


