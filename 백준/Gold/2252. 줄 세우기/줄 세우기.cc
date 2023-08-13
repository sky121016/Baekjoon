// 2252 줄세우기
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
vector<int> out[32010];
int in[32010];
vector<int> result;

void Sort(){
    queue<int> q;

    for(int i = 1; i <= N; i++){
        if(in[i] == 0){
            q.push(i);
        }
    }

    int v;
    for(int i = 0; i < N; i++){
        if(q.empty()){return ;}

        v = q.front();
        result.push_back(v);
        q.pop();


        int w;
        for(int j = 0; j < out[v].size(); j++){
            w = out[v][j];
            in[w]--;

            if(in[w] == 0){
                q.push(w);
            }

        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int a, b;

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        out[a].push_back(b);
        in[b] ++;
    }

    Sort();


    for(int i = 0; i<N; i++){
        cout<<result[i]<<" ";
    }

}
