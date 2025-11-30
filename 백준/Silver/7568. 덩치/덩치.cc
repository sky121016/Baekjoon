// 7568 덩치

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int height[50];
    int weight[50];
    int count[50];

    
    for(int i = 0; i<n; i++){
        cin>>height[i];
        cin>>weight[i];
        count[i] = 1;
    }

    for(int j = 0; j<n-1; j++){
        for(int i = j+1; i<n; i++){
            if(height[j] < height[i] && weight[j] < weight[i]){
                count[j] = count[j] + 1;
            }else if(height[j] > height[i] && weight[j] > weight[i]){
                count[i] = count[i] + 1;
            }
        }
    }

    for(int i = 0; i<n; i++){
        cout<<count[i]<<endl;
    }

}