// 17299
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int A[1010101];
int NGF[1010101];
int F[1010101];
stack<int> s;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;    
    for(int i = 0; i<n; i++){
        cin >> A[i];
        F[A[i]]++;
    }

    for(int i = n-1; i>=0; i--){

        while(!s.empty() && F[A[i]] >= F[s.top()]) {
            s.pop();
        }

        if(s.empty()){
            NGF[i] = -1;
        }else{
            NGF[i] = s.top();
        }

        s.push(A[i]);

    }

    for(int i = 0; i<n; i++){
        cout << NGF[i] << " ";
    }
}
