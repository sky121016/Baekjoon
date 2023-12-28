// 18258
#include<iostream>
#include<string>
#include<queue>
using namespace std;

int N;
int cnt;
queue<int> q;
string cmd;
int num;
int front;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    while(cnt < N){
        cin >> cmd;

        if(cmd == "push"){
            cin >> num;
            q.push(num);
        }else if(cmd == "pop"){
            if(q.empty()){
                cout << "-1\n";
            }else{
                cout << q.front() << "\n";
                q.pop();
            }
        }else if(cmd == "size"){
            if(q.empty()){
                cout << "0\n";
            }else{
                cout << q.size() << "\n";
            }
        }else if(cmd == "empty"){
            if(q.empty()){
                cout << "1\n";
            }else{
                cout << "0\n";
            }
        }else if(cmd == "front"){
            if(q.empty()){
                cout << "-1\n";
            }else{
                cout << q.front() << "\n";
            }
        }else if(cmd == "back"){
            if(q.empty()){
                cout << "-1\n";
            }else{
                cout << q.back() << "\n";
            }
        }
        cnt++;
    }
}
