
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <map>
#include <set>

using namespace std;

int a, b;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    while(true){
        cin >> a >> b;

        if(a == 0 && b == 0){
            break;
        }

        if(a > b){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }

}

