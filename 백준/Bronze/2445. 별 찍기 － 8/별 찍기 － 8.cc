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

    for(int i = 1; i<=n; i++){
        for(int j = 0; j<i; j++){
            cout<<"*";
        }
        for(int j = 0; j<(n-i)*2; j++){
            cout<<" ";
        }
        for(int j = 0; j<i; j++){
            cout<<"*";
        }
        cout<<"\n";
    }

    for(int i = n-1; i>0; i--){
        for(int j = 0; j<i; j++){
            cout<<"*";
        }
        for(int j = 0; j<(n-i)*2; j++){
            cout<<" ";
        }
        for(int j = 0; j<i; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}

