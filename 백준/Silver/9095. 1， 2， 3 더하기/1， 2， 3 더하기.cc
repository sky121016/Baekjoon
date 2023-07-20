// 9095 1,2,3 더하기
#include<iostream>
#include<vector>
using namespace std;

int arr[12];

int add(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(n == 3) return 4;

    if(arr[n] != 0){
        return arr[n];
    }

    return arr[n] = add(n-3) + add(n-2) + add(n-1);
}

int main(){
    int t;
    cin>>t;

    int n;

    for(int i = 0; i<t; i++){
        cin>>n;
        cout << add(n) << "\n";
    }

}


