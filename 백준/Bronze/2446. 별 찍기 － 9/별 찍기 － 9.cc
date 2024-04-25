#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            cout<<" ";
        }
        for(int j = 2*n-(2*i)-1; j>0; j--){
            cout<<"*";
        }
        cout<<"\n";
    }

    for(int i = n-1; i>0; i--){
        for(int j = 0; j<i-1; j++){
            cout<<" ";
        }
        for(int j = 2*n-(2*i)+1; j>0; j--){
            cout<<"*";
        }
        cout<<"\n";
    }

}

