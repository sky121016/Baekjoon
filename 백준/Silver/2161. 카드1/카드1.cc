// 2161
#include<iostream>
#include<queue>

using namespace std;

int n;
queue<int> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i<=n; i++){
        q.push(i);
    }

    while(q.size()>1){
        // 제일 위에 카드 버려
        cout << q.front() << " ";
        q.pop();    

        q.push(q.front());
        q.pop();
    }

    cout << q.front() << " ";
}


