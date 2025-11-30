// 10814
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>

using namespace std;

int n;
deque<int> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    string cmd;
    int num;
    for (int i = 0; i < n; i++){
        cin >> cmd;
        if(cmd == "push_front"){
            cin >> num;
            s.push_front(num);
        }else if(cmd == "push_back"){
            cin >> num;
            s.push_back(num);
        }else if(cmd=="pop_front"){
            if(!s.empty()){
                cout<<s.front()<<"\n";
                s.pop_front();
            }else{
                cout << "-1\n";
            }
        }else if(cmd == "pop_back"){
            if(!s.empty()){
                cout<<s.back()<<"\n";
                s.pop_back();
            }else{
                cout << "-1\n";
            }
        }else if(cmd=="front"){
            if(s.empty()){
                cout<<"-1";
            }else{
                cout << s.front();
            }
            cout<<"\n";
        }else if(cmd == "back"){
            if(s.empty()){
                cout<<"-1";
            }else{
                cout<<s.back();
            }
            cout<<"\n";
        }else if(cmd=="size"){
            cout<< s.size()<<"\n";
        }else if(cmd == "empty"){
            if(s.empty()){
                cout<<"1";
            }else{
                cout << "0";
            }
            cout << "\n";
        }
    }
}
