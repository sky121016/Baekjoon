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


    for(int i = 0; i<n; i++){
        for(int j = 0; j<3*n; j++){
            cout<<"@";
        }
        for(int j = 0; j<n; j++){
            cout<<" ";
        }
        for(int j = 0; j<n; j++){
            cout<<"@";
        }

        cout<<"\n";
    }



    for(int i = 0; i<3*n; i++){
        for(int j = 0; j<n; j++){
            cout<<"@";
        }
        for(int j = 0; j<n; j++){
            cout<<" ";
        }
        for(int j = 0; j<n; j++){
            cout<<"@";
        }
        for(int j = 0; j<n; j++){
            cout<<" ";
        }
        for(int j = 0; j<n; j++){
            cout<<"@";
        }
        cout<<"\n";
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<"@";
        }
        for(int j = 0; j<n; j++){
            cout<<" ";
        }
        for(int j = 0; j<3*n; j++){
            cout<<"@";
        }

        cout<<"\n";
    }


}