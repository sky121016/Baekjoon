// 1011
#include<iostream>
#include<vector>
using namespace std;

int t;
int x, y;

long long i, j, num;

long long fly(long long n){
    num = 0;
    i = j = 0;
    while(num < n){
        j++;
        if(j%2 == 0){
            i = j/2;
        }else{
            i = (j+1)/2;
        }
        num += i;
    }

    return j;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;

    for(int i = 0; i<t; i++){
        cin >> x >> y;
        cout << fly(y - x) << "\n";
    }
}
