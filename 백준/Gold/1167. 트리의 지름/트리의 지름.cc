
// 1167
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

// int edge[100001][100001];
vector< pair<int,int> > edge[100001];
int V;
int temp, v, e;
bool visited[100001];
int maxSum;
int maxNode;

void dfs(int vertex, int sum){
    visited[vertex] = true;
    for(int i = 0; i<edge[vertex].size(); i++){
        if(!visited[edge[vertex][i].first]){
            sum += edge[vertex][i].second;
            dfs(edge[vertex][i].first, sum);
            sum -= edge[vertex][i].second;
        }
    }

    if (maxSum < sum){
        maxSum = sum;
        maxNode = vertex;
    }

    visited[vertex]=false;

    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V;

    for(int i = 0; i<V; i++){
        cin >> temp;
        while (1){
            cin >> v;
            if(v == -1){
                break;
            }else{
                cin >> e;
                edge[temp].push_back(make_pair(v,e));
            }
        }
    }

    dfs(1,0);
    dfs(maxNode,0);
    cout << maxSum;
}
