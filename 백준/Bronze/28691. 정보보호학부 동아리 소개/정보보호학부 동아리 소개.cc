

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

char c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> c;
    if(c == 'M'){
        cout << "MatKor";
    }else if(c == 'W'){
        cout<<"WiCys";
    }else if(c == 'C'){
        cout<<"CyKor";
    }else if(c == 'A'){
        cout<<"AlKor";
    }else if(c == '$'){
        cout<<"$clear";
    }
}
