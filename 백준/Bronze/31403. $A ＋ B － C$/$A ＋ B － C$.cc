
// 2357

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;


string a, b, c;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;

    cout << stoi(a) + stoi(b) - stoi(c)<<"\n" ;

    cout << stoi(a + b) - stoi(c);
}


