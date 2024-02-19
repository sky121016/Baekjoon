// 13904
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
int n, m;
int a, b;
int in[32001];
vector<int> out[32001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i<m; i++){
        cin >> a >> b;
        out[a].push_back(b);
        in[b]++;
    }

    for(int i = 1; i<=n; i++){
        if(in[i] == 0){
            pq.push(i);
        }
    }

    while(!pq.empty()){
        int v = pq.top();
        pq.pop();
        cout<<v<<" ";
        for(int i = 0; i<out[v].size(); i++){
            in[out[v][i]]--;
            if(in[out[v][i]]==0){
                pq.push(out[v][i]);
            }
        }
    }

}



