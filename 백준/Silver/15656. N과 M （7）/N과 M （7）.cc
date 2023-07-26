// 15656 N과 M 7

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n, m;
vector<int> result;
vector<int> num;

void dfs(int value, int count){
    if(count == m){
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
        
    }else{
        for(int i = 0; i < n; i++){
            result.push_back(num[i]);

            dfs(i+1, count + 1);

            result.pop_back();
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
