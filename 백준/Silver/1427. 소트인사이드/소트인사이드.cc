#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int num[11];
    
    string temp;
    cin>>temp;
    for(int i = 0; i<temp.length(); i++){
        num[i] = temp[i] - '0';
    }

    sort(num, num+temp.length());
    for(int i = temp.length()-1; i>=0; i--){
        cout<<num[i];
    }

}
