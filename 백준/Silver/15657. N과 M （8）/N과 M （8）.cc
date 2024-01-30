// 15657
#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<int> result;

void dfs(int idx, int cnt){
    if(cnt == m){
        for(int i = 0; i<m; i++){
            cout<<result[i]<<" ";
        }
        cout << "\n";
    }else{
        for(int i = idx; i<n; i++){
            result.push_back(arr[i]);

            dfs(i, cnt + 1);

            result.pop_back();
        }
    }

}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    dfs(0,0);


}

