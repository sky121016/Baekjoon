


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

string n;
bool contain;
bool divisible;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int number = stoi(n);
    for(int i = 0; i<n.length(); i++){
        if(n[i] == '7'){
            contain = true;
            break;
        }
    }

    if(number % 7 == 0){
        divisible = true;
    }


    if(!contain && !divisible){
        cout << 0;
    }else if(!contain && divisible){
        cout << 1;
    }else if(contain && !divisible){
        cout << 2;
    }else if(contain && divisible){
        cout<< 3;
    }


    
}
