


// 1874 스택 수열
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int num=1;
int n;
stack<int> s;
int arr[101010];
vector<char> ans;

void solution(){

    for(int i = 0; i<n; i++){
        if(!s.empty() && s.top() == arr[i]){
            s.pop();
            ans.push_back('-');
        }else if(num <= arr[i]){
            while(num <= arr[i]){
                s.push(num);
                num++;
                ans.push_back('+');
            }
            s.pop();
            ans.push_back('-');
        }else if(!s.empty() && s.top() > arr[i]){
            cout<<"NO";
            return ;
        }
    
    }


    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    }



}

int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    solution();
}