// 15649 n과 m

#include <iostream>
#include <string>
#include<vector>

using namespace std;

int n, m;
vector<int> result;
bool visited[9];

void dfs(int count){
    if(count == m){
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
        
    }else{
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                visited[i] = true;
                result.push_back(i);

                dfs(count+1);

                visited[i] = false;
                result.pop_back();
            }
        }

    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    dfs(0);

}

