
// 17265
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = n; i>0; i--){
        for(int j = 0; j<n-i; j++){
            cout<<" ";
        }
        for(int j = 0; j<2*i-1; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}
