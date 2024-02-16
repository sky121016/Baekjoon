// 1167
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

int n, m;
vector<int> result;
int a[9];


void dfs(int num, int cnt){
    if(cnt == m){
        for(int i = 0; i<m; i++){
            cout << result[i] << " ";
        }
        cout<<"\n";
    }else{
        int last = -1;
        for(int i = num; i<n; i++){
            if(last != a[i]){
                result.push_back(a[i]);
                last = a[i];
                
                dfs(i, cnt + 1);
                result.pop_back();
            }
        }
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);

    dfs(0,0);
}




