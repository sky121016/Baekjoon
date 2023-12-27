// 1934
#include<iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    if(b > a){
        swap(a,b);
    }
    return gcd(b, a%b);
}

int main(){
    int a, b;
    int t;
    cin >> t;
    for(int i = 0; i<t; i++){
        cin >> a >> b;
        cout << (a*b)/gcd(a, b)<<endl;
    }
}
