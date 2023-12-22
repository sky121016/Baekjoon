#include<iostream>
#include<stack>
using namespace std;

int main(){
    int k;
    cin>>k;

    int a;

    stack<int> n;
    for(int i = 0; i<k; i++){
        cin>>a;
        if(a==0){
            n.pop();
        }else{
            n.push(a);    
        }
    }
    int sum = 0;


    while(!n.empty()){
        sum += n.top();
        n.pop();
    }

    cout<<sum<<endl;
}


