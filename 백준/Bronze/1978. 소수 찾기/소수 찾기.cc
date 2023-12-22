#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    int count=0;
    int num;
    for(int i=0; i<N; i++){
        cin>>num;
        for(int j = 2; j<=num; j++){
            if(num%j==0){
                if(num==j){
                    count++;
                }else{
                    break;
                }
            }
        }
    }
    cout<<count<<endl;
}

