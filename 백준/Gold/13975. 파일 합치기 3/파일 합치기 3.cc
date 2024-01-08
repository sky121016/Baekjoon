// 13975
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long> > pq;
int t;
int K;
long long a, b;
long long sum;
long long total;
long long temp;

void File(int k){
    while(!pq.empty()){
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();

        sum = a + b;
        total += sum;

        if(!pq.empty()){
            pq.push(sum);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for(int i = 0; i<t; i++){
        total = 0;
        sum = 0;
        cin >> K;
        for(int j = 0; j<K; j++){
            cin >> temp;
            pq.push(temp);
        }

        File(K);
        cout << total<<"\n";
        
        while(!pq.empty()){
            pq.pop();
        }
    }
}

