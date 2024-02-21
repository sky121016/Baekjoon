// 2109
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;
priority_queue<pair<int, int> > pq;      // p,d
int sum;
int a[10101];
int maxD;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int p, d;
    for(int i = 0; i<n; i++){
        cin >> p >> d;
        pq.push(make_pair(p, d));
        if(maxD < d){
            maxD = d;
        }
    }



    for(int i = 0; i<n; i++){
        int P = pq.top().first;
        int D = pq.top().second;        // d

        while(D > 0){
            if(a[D] == 0){
                a[D] = P;
                break;
            }else{
                D--;
            }
        }
        pq.pop();
    }

    for(int i = 1; i<=maxD; i++){
        sum += a[i];
    }
    cout << sum;
}

