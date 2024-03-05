// 11729
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int n;
int cnt;
vector< pair<int, int> > r;

void Hanoi(int num, int A, int B, int C){
    if(num > 0){
        cnt++;
        Hanoi(num - 1, A, C, B);
        r.push_back(make_pair(A,C));
        Hanoi(num - 1, B, A, C);
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    Hanoi(n, 1, 2, 3);

    cout << cnt << "\n";

    for(int i = 0; i<r.size(); i++){
        cout << r[i].first << " " << r[i].second << "\n";
    }
}
