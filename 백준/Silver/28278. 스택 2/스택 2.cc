// 28278
#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
int cmd;
int n;
int num;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while(n > 0){
        cin >> cmd;
        if(cmd == 1){
            cin >> num;
            s.push(num);
        }else if(cmd == 2){
            if(!s.empty()){
                cout << s.top()<<"\n";
                s.pop();
            }else{
                cout<<"-1\n";
            }
        }else if(cmd == 3){
            cout<<s.size()<<"\n";
        }else if(cmd == 4){
            if(s.empty()){
                cout<<"1\n";
            }else{
                cout<<"0\n";
            }
        }else if(cmd == 5){
            if(!s.empty()){
                cout<<s.top()<<"\n";
            }else{
                cout<<"-1\n";
            }
        }

        n--;
    }



}


