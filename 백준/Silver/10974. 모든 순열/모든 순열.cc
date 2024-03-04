// 100974
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int n;
int visited[9];
vector<int> r;

void P(int cnt){
    if(cnt == n){
        for(int i = 0; i<r.size(); i++){
            cout<<r[i]<<" ";
        }
        cout << "\n";
    }else{
        for(int i = 1; i<=n; i++){
            if(!visited[i]){
                visited[i] = true;
                r.push_back(i);
                P(cnt + 1);
                visited[i] = false;
                r.pop_back();
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    P(0);

}
