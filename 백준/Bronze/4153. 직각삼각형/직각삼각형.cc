// 4153

#include<iostream>
#include<algorithm>
using namespace std;


int arr[3];
bool answer = false;

int main(){
    
    while(1){
        cin >> arr[0] >> arr[1] >> arr[2];

        if(arr[0]==0 && arr[1]==0 && arr[2]==0){
            break;
        }

        sort(arr, arr + 3);
        
        for(int i = 0; i<3; i++){
            arr[i] = arr[i] * arr[i];
        }


        if(arr[2] == arr[0] + arr[1]){
            answer = true;
        }

        if(answer){
            cout<<"right\n";
        }else{
            cout<<"wrong\n";
        }

        answer = false;
    }

}