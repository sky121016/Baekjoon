// 10866
#include<iostream>
#include<string>
#include<deque>

using namespace std;

deque <int> d;

string cmd;
int N;
int cnt;
int num;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    while(cnt < N){
        cin >> cmd;

        if(cmd == "1"){
            cin >> num;
            d.push_front(num);
        }else if(cmd == "2"){
            cin >> num;
            d.push_back(num);
        }else if(cmd == "3"){
            if(d.empty()){
                cout << "-1\n";
            }else{
                cout << d.front()<<"\n";
                d.pop_front();
            }
        }else if(cmd == "4"){
            if(d.empty()){
                cout << "-1\n";
            }else{
                cout << d.back()<<"\n";
                d.pop_back();
            }
        }else if(cmd == "5"){
            cout<<d.size()<<"\n";
        }else if(cmd == "6"){
            cout<<d.empty()<<"\n";
        }else if(cmd == "7"){
            if(d.empty()){
                cout << "-1\n";
            }else{
                cout<<d.front()<<"\n";
            }
        }else if(cmd == "8"){
            if(d.empty()){
                cout << "-1\n";
            }else{
                cout<<d.back()<<"\n";
            }
        }

        cnt++;
    }

}

