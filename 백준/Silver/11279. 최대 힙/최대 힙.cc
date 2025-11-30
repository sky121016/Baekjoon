// 10814
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n;

priority_queue<int> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int x;
    for(int i = 0; i<n; i++){
        cin >> x;
        if(x==0){
            if(q.empty()){
                cout<<"0\n";
            }else{
                cout << q.top() << "\n";
                q.pop();
            }
        }else{
            q.push(x);
        }
    }
}