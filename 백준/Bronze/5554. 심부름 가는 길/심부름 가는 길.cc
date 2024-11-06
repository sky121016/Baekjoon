// 2357

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a, b, c, d;
int sum;
int Min;
int sec;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c >> d;

    sum = a + b + c + d;

    Min = sum / 60;
    sec = sum % 60;

    cout<<Min<<"\n"<<sec;
}
