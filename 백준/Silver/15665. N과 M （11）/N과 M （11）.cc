// 15665
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int a[8];
vector<int> result;


void dfs(int num, int cnt){
    if(cnt == m){
        for(int i = 0; i<m; i++){
            cout<<result[i]<<" ";
        }
        cout<<"\n";
    }else{
        int last = -1;
        for(int i = 0; i<n; i++){
            if(last == a[i]){
                continue;
            }
            result.push_back(a[i]);
            last = a[i];

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
    for(int i = 0;i<n; i++){
        cin>>a[i];
    }

    sort(a, a + n);

    dfs(0,0);


}



