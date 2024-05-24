
// 1738
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;


int n, m;
int dist[101];
// vector<int> edge[101];
// int edge[101][101];
stack<int> s;
bool error;
int p[101];
int inf = 987654321;
vector<int> adj[101];

class Edge{
public:
    int s;
    int e;
    int weight;

    void setEdge(int s, int e, int w){
        this->s = s;
        this->e = e;
        weight = w;
    }
};

bool visited[101];
Edge edge[20010];


void shortestPath(){
    int s, e, w;
    for(int u = 1; u<=n; u++){
        for(int i = 0; i<m; i++){
            w = edge[i].weight;
            s = edge[i].s;
            e = edge[i].e;
            if(dist[s] == inf){
                continue;
            }
            if(dist[e] > dist[s] + w){
                if(u == n && visited[s]){
                    error = true;
                }
                dist[e] = dist[s] + w;
         
                p[e] = s;
            }
        }
    }

   

}



queue<int> q;
void canVisit(){
    visited[n] = true;
    q.push(n);

    int v;
    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i<adj[v].size(); i++){
            int ne = adj[v][i];
            if(!visited[ne]){
                visited[ne] = true;
                q.push(ne);
            }
        }
    }


}


void path(int pre){
    s.push(p[pre]);
    if(p[pre] == 1){
        return;
    }
    path(p[pre]);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int u, v, w;
    for(int i = 0; i<m; i++){
        cin >> u >> v >> w;
        edge[i].setEdge(u, v, w *-1);
        adj[v].push_back(u);
    }

    for(int i = 2; i<=n; i++){
        dist[i] = inf;
    }
    p[1] = 1;

    canVisit();
  
    shortestPath();

    if(error){
        cout << "-1";
    }else{

        s.push(n);

        path(n);
    
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }

    }
}
