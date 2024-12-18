


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

vector<string> s;
vector<int> n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a;
    int b;
    for(int i = 0; i<7; i++){
        cin >> a >> b;
        s.push_back(a);
        n.push_back(b);
    }

    int max = 0;
    int maxI = 0;

    for(int i = 0; i<7; i++){
        if(n[i] > max){
            max = n[i];
            maxI = i;
        }
    }

    cout<<s[maxI];
}
