#include<iostream>
using namespace std;

// 전역변수
int check[1000001];         // = 0
int M, N;


void prime(){
    check[1] = 1;
    for(int i = 2; i<=N; i++){
        if(check[i] == 0){
            for(int j = i*2; j<=N; j+=i){
                check[j] = 1;
            }
        }
    }
}


int main(){
    cin>>M>>N;
    prime();

    for(int i = M; i<=N; i++){
        if(check[i] == 0){
            cout<<i<<'\n';
        }
    }
    
 
}
