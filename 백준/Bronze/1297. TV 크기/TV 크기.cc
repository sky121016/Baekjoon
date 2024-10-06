// 17265
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

double d;
double w, h;

int rw, rh;
double x;
double x2;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> d >> h >> w;

    x2 = d * d / (h * h + w * w);

    x = sqrt(x2);

    rh = x * h;
    rw = x * w;

    cout << rh << " " << rw;
}

