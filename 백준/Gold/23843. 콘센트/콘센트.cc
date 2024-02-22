// 2109
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
int t[11];
int minIdx;
priority_queue<int> pq;
int maxT;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        pq.push(temp);
    }

    while(!pq.empty()){
        minIdx = 0; 
        for(int i = 0; i<m-1; i++){
            if(t[i] > t[i+1]){
                minIdx = i+1;
            }
        }
        t[minIdx] += pq.top();

        pq.pop();
    }

    maxT = t[0];
    for(int i = 0; i<m-1; i++){
        if(t[i] < t[i+1]){
            maxT = t[i+1];
        }
    }

    cout << maxT;
}



