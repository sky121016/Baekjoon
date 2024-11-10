// 2357

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int x, y;
int n;
int ansX, ansY;
int minDis;
int nx, ny;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> y;
    cin >> n;

    minDis = 300000;

    for(int i = 0; i<n; i++){
        cin >> nx >> ny;
        if(abs(nx-x) + abs(ny-y) < minDis){
            ansX = nx;
            ansY = ny;
            minDis = abs(nx-x) + abs(ny-y);
        }
    }

    cout << ansX << " " << ansY;
}

