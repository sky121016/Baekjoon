#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        for(int k = 1; k<n-i; k++){
            cout<<' ';
        }
        for(int j = 0; j<2*i+1; j++){
            cout<<"*";
        }
        cout<<"\n";
    }

    for(int i = n-2; i>=0; i--){
        for(int k = 1; k<n-i; k++){
            cout<<' ';
        }
        for(int j = 0; j<2*i+1; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}