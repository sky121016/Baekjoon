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


    cin>>n;

    for(int i = 0; i<n; i++){
        for(int j = 1; j<n-i; j++){
            cout<<" ";
        }
        for(int j = 1; j<=2*(i+1)-1; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
 
}

