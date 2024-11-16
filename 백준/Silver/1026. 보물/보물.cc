// 3009
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n;
vector<int> A;
vector<int> B;

int sum;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        A.push_back(temp);
    }
   
    for(int i = 0; i<n; i++){
        cin >> temp;
        B.push_back(temp);
    }

    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    for(int i = 0; i<n; i++){
        sum += A[i] * B[i];
    }

    cout << sum;
}


