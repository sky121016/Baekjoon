// 1914
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int n;
long long k;
string s;

void hanoi(int num, int a, int b, int c){
    if(num == 0){
        return ;
    }
    hanoi(num - 1, a, c, b);

    cout << a << " " << c << "\n";
    hanoi(num - 1, b, a, c);


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    s = to_string(pow(2, n));
    int x = s.find('.');
    s = s.substr(0, x);
    s[s.length() - 1] -= 1;

    cout << s << "\n";

    if(n <= 20){
        hanoi(n, 1, 2, 3);
    }

}