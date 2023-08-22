#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    int a, b;
    for(int i = 0; i<t; i++){
        cin >> a >> b;
        cout<<a+b<<"\n";
    }
}