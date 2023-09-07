// 2738
#include<iostream>
using namespace std;

int N, M;
int A[101][101];
int B[101][101];
int C[101][101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> A[i][j];
        }
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> B[i][j];
        }
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            C[i][j] = A[i][j] + B[i][j];
            cout<<C[i][j]<<" ";
        }
        cout<<"\n";
    }



}

