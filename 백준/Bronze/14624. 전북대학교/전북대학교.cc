#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    if(n % 2 == 0){
        cout<<"I LOVE CBNU";
    }else{
        for(int i = 0; i<n; i++){
            cout<<"*";
        }
        cout << "\n";

        for(int i = n/2; i>=0; i--){
            for(int j = i; j>0; j--){
                cout<<" ";
            }
            cout<<"*";
            for(int j = 0; j<2*(n/2-i)-1; j++){
                cout<<" ";
            }
            if(i != n/2){
                cout<<"*";
            }
            cout << "\n";
        }
    }
}
