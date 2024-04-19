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
        for(int j = 0; j<n; j++){
            if(j>=i){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<"\n";
    }
}
