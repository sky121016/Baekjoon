#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

string a, b;
int num[100][17];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;

    for(int i = 0; i < 8; i++){
        num[0][2*i] = int(a[i]-'0');
        num[0][2*i+1] = int(b[i]-'0');
    }

    for(int i = 1; i<15; i++){
        for(int j = 0; j<16-i; j++){
            num[i][j] = (num[i-1][j] + num[i-1][j+1]) % 10;
        }
    }

    cout<<num[14][0]<<num[14][1];

}
