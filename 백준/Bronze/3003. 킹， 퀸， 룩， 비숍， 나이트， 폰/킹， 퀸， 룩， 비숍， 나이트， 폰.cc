#include<iostream>
#include<vector>
using namespace std;

int chess[6] = {1, 1, 2, 2, 2, 8};
int myPiece[6];

int main(){

    for(int i = 0; i<6; i++){
        cin>>myPiece[i];
        cout<<chess[i] - myPiece[i]<<" ";
    }
}

