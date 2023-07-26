
// 15655 N과 M 6

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int n, m;
vector<int> result;
vector<int> num;
bool visited[10001];

void dfs(int value, int count){
    if(count == m){
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
        
    }else{
        for(int i = value; i < n; i++){
            if(!visited[i]){
                visited[i] = true;
                result.push_back(num[i]);

                dfs(i+1, count + 1);

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

    int temp;
    for(int i = 0; i<n; i++){
        cin>>temp;
        num.push_back(temp);
    }

    sort(num.begin(), num.end());

    dfs(0,0);


}

