// 17265
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;


int n;
priority_queue<int> a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        a.push(temp);
    }

    for(int i = 0; i<n; i++){
        cout<<a.top()<<"\n";
        a.pop();
    }
}
