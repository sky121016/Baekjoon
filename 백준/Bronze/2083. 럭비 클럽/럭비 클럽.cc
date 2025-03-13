#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a;
    int b, c;

    while(true){
        cin >> a >> b >> c;
        
        if(a == "#" && b == 0 && c == 0){
            break;
        }

        cout << a << " ";
        if(b > 17 || c >= 80){
            cout<<"Senior\n";
        }else{
            cout<<"Junior\n";
        }
    }



}
