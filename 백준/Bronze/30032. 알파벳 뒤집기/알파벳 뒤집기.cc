#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int n;
int d;
string s;

void printC(char c){
    if(d == 1){
        if(c == 'd'){
            cout<<"q";
        }else if(c == 'b'){
            cout<<"p";
        }else if(c == 'q'){
            cout<<"d";
        }else if(c == 'p'){
            cout<<"b";
        }
    }else if(d == 2){
        if(c == 'd'){
            cout<<"b";
        }else if(c == 'b'){
            cout<<"d";
        }else if(c == 'q'){
            cout<<"p";
        }else if(c == 'p'){
            cout<<"q";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> d;

    for(int i = 0; i<n; i++){
        cin >> s;
        for(int j = 0; j<n; j++){
            printC(s[j]);
        }
        cout<<"\n";
    }
}
