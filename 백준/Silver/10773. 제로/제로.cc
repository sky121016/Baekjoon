

// 10773
#include<iostream>
#include<stack>

using namespace std;

int K;
stack<int> s;
int num;
int sum;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;

    for(int i = 0; i<K; i++){
        cin >> num;
        if(num == 0){
            sum -= s.top();
            s.pop();
        }else{
            s.push(num);
            sum += num;
        }
    }

    cout << sum;
}
