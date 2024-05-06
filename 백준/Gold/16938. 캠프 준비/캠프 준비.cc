// 16938
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>

using namespace std;

int n, l, r, x;
int a[16];
vector<int> v;
int cnt;
int m;
int M;

void dfs(int sum, int i){

    if(!v.empty()){
        m = *min_element(v.begin(), v.end());
        M = *max_element(v.begin(), v.end());

    }

    if(sum >= l && sum <= r && M-m >= x){
        cnt++;
    }

    for(int j = i; j<n; j++){
        v.push_back(a[j]);
        dfs(sum+a[j], j+1);
        v.pop_back();
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r >> x;

    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    
    dfs(0, 0);

    cout << cnt;
}


