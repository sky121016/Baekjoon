// 15903
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long> > pq;
int n, m;
long long a, b;
long long sum;
long long total;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    long long temp;

    for(int i = 0; i<n; i++){
        cin >> temp;
        pq.push(temp);
    }

   
    for(int i = 0; i<m; i++){
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();

        sum = a + b;

        pq.push(sum);
        pq.push(sum);
    }

    
    while(!pq.empty()){
        total += pq.top();
        pq.pop();
    }

    cout << total;
}

