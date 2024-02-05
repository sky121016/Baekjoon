// 11279
#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

priority_queue<int> pq;
int n;
int temp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> temp;
        if(temp != 0){
            pq.push(temp);
        }else{
            if(!pq.empty()){
                cout << pq.top() << "\n";
                pq.pop();
            }else{
                cout<<"0\n";
            }
        }
    }
}

