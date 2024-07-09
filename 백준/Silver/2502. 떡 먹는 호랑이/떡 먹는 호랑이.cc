#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int D, K;
int A, B;
int a[31];
int b[31];
int temp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> D >> K;
    a[1] = 1;
    b[2] = 1;

    for(int i = 3; i<=D; i++){
        a[i] = a[i - 1] + a[i - 2];
        b[i] = b[i - 1] + b[i - 2];
    }

    for(int i = 1; i<=K; i++){
        for(int j = 1; j<=K; j++){
            temp = a[D] * i + b[D] * j;
            if(temp == K){
                cout << i << "\n";
                cout << j;
                return 0;
            }
        }
    }
}


