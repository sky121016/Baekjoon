#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cstdlib>
using namespace std;

int r1, r2;
int s;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r1 >> s;

    r2 = 2 * s - r1;

    cout << r2;
}


