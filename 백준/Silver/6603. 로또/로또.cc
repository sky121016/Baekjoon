#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int k;
int temp;
vector<int> S;
vector<int> l;

bool visited[50];


void dfs(int n, int cnt){
    if(cnt == 6){
        for(int i = 0; i<6; i++){
            cout<<l[i]<<" ";
        }
        cout<<"\n";
    }else{
        for(int i = n; i < S.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                l.push_back(S[i]);
          

                dfs(i, cnt+1);

                visited[i] = false;
                l.pop_back();

            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    k = -1;

    int cnt=0;

    while(k != 0){
        cin >> k;
        for(int i = 0; i<k; i++){
            cin >> temp;
            S.push_back(temp);
        }

        dfs(0, 0);

        for(int i = 0; i<k; i++){
            visited[i] = false;
        }
        while(!l.empty()){
            l.pop_back();
        }
        while(!S.empty()){
            S.pop_back();
        }

        cout<<"\n";

    }
}