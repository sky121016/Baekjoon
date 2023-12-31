// 10845

#include<iostream>
#include<queue>
#include<string>
using namespace std;

queue<int> q;
int n;
string cmd;
int num;

int main(){
   ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  cin >> n;


  for(int i = 0; i<n; i++){
    cin >> cmd;
    if(cmd == "push"){
      cin >> num;
      q.push(num);
    }else if(cmd == "pop"){
      if(q.empty()){
        cout<<"-1\n";
      }else{
        cout << q.front() << "\n";  
        q.pop();
      }
    }else if(cmd == "size"){
      cout << q.size() << "\n";
    }else if(cmd == "empty"){
      if(q.empty()){
        cout<<"1\n";
      }else{
        cout<<"0\n";
      }
    }else if(cmd == "front"){
      if(q.empty()){
        cout<<"-1\n";
      }else{
        cout << q.front() << "\n";  
      }
    }else if(cmd == "back"){
      if(q.empty()){
        cout<<"-1\n";
      }else{
        cout << q.back() << "\n";
      }
    }
  }
}
