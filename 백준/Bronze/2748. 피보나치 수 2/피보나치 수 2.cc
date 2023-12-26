// 2748 피보나치
#include<iostream>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin>>n;
    
    long long arr[91]={0,};
    arr[0] = 0;
    arr[1] = 1;

    for(int i = 2; i<=n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }

    cout<<arr[n];

}

