// 3009
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a, b;
queue<int> x;
queue<int> y;
bool xb[1001];
bool yb[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i<3; i++){
        cin >> a >> b;
        xb[a] = !xb[a];
        yb[b] = !yb[b];

        x.push(a);
        y.push(b);
    }


    int v;
    while(!x.empty()){
        v = x.front();
        x.pop();

        if(xb[v]){
            cout << v << " ";
            break;
        }

    }

    while(!y.empty()){
        v = y.front();
        y.pop();

        if(yb[v]){
            cout << v;
            break;
        }
    }
}
