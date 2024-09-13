// 2660
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int node[51][51];
int n;
int score[51];


void shortest(){
    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(node[i][j] > node[i][k] + node[k][j]){
                    node[i][j] = node[i][k] + node[k][j];
                }
            }
        }
    }
}

int minScore = 1000;
int cnt;

void pick(){
    for(int i = 1; i<=n; i++){
        score[i] = *max_element(node[i]+1, node[i]+n+1);
        if(minScore>score[i]){
            cnt = 1;
            minScore = score[i];
        }else if(minScore == score[i]){
            cnt++;
        }
    }

    cout << minScore << " " << cnt << "\n";

    for (int i = 1; i <= n; i++){
        if(score[i] == minScore){
            cout<<i<<" ";
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int a, b;

    for(int i = 0; i<=n; i++){
        fill(node[i], node[i] + n+1, 1000);
        node[i][i] = 0;
    }

    while(true){
        cin >> a >> b;
        if(a == -1 && b == -1){
            break;
        }
        node[a][b] = 1;
        node[b][a] = 1;
    }

    shortest();

    pick();



}

