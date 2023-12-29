// 10866
#include<iostream>
#include<string>

using namespace std;

int d[20001];
int head = 10000;
int tail = 10001;
string cmd;
int N;
int cnt;
int num;

bool isEmpty(){
    if((tail - head) == 1){
        return true;
    }else{
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    while(cnt < N){
        cin >> cmd;

        if(cmd == "push_front"){
            cin >> num;
            d[head] = num;
            head--;
        }else if(cmd == "push_back"){
            cin >> num;
            d[tail] = num;
            tail++;
        }else if(cmd == "pop_front"){
            if(isEmpty()){
                cout << "-1\n";
            }else{
                cout << d[++head]<<"\n";
            }
        }else if(cmd == "pop_back"){
            if(isEmpty()){
                cout << "-1\n";
            }else{
                cout << d[--tail] << "\n";
            }
        }else if(cmd == "size"){
            cout << tail - head - 1 << "\n";
        }else if(cmd == "empty"){
            cout << isEmpty() << "\n";
        }else if(cmd == "front"){
            if(isEmpty()){
                cout << "-1\n";
            }else{
                cout << d[head + 1] << "\n";
            }
        }else if(cmd == "back"){
            if(isEmpty()){
                cout << "-1\n";
            }else{
                cout << d[tail - 1] << "\n";
            }
        }

        cnt++;
    }

}

