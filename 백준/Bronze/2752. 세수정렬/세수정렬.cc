// 17265

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>a[0];
    cin>>a[1];
    cin>>a[2];

    sort(a, a+3);

    cout<<a[0]<<" ";
    cout<<a[1]<<" ";
    cout<<a[2];
  
}
