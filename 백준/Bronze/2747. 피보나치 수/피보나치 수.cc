// 2747
#include<iostream>
using namespace std;

long long f[46];

long long fibo(int n){
    if(f[n] != 0){
        return f[n];
    }
    if(n == 0){return f[n]=0;}
    else if(n == 1){return f[n]=1;}
    else{
        return f[n] = fibo(n - 1) + fibo(n - 2);
    }
}

int main(){
    int n;
    cin >> n;
    cout << fibo(n);
}


