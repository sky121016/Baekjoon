
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

vector<int> s;
int science;
int social;
int total;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int temp;

    for(int i = 0; i<6; i++){
        cin >> temp;
        s.push_back(temp);
    }

    sort(s.begin(), s.begin()+4);
    sort(s.begin()+4, s.end());

    for(int i = 3; i>0; i--){
        total += s[i];
    }
    total+=s[5];

    cout<<total;
}

