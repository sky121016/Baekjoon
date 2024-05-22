// 16562
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>

using namespace std;

int n, m, k;
int cost[10101];
int p[10101];
bool visited[10101];
int sum;

int find_parent(int x){
    if(p[x] == x){
        return p[x];
    }
    return p[x] = find_parent(p[x]);
    
}


void make_union(int v, int w){
    v = find_parent(v);
    w = find_parent(w);

    if(v != w){
        if(cost[v] <= cost[w]){
            p[w] = v;
        }else{
            p[v] = w;
        }
    }

   
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for(int i = 1; i<=n; i++){
        cin >> cost[i];
        p[i] = i;
    }


    int v, w;
    for(int i = 0; i<m; i++){
        cin >> v >> w;
        make_union(v, w);
    }


    for(int i = 1; i<=n; i++){
        int c = find_parent(p[i]);
        if(!visited[c]){
            sum += cost[c];
            visited[c] = true;
        }
    }

    if(sum <= k){
        cout << sum;
    }else{
        cout << "Oh no";
    }
}

