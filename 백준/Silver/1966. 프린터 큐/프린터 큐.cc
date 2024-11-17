#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

int t;
int n, m;

int cnt;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t > 0){
        queue<pair<int, int> > q;
        priority_queue<int> pq;
        
        cin >> n >> m;
        cnt = 0;

        int temp;

        for(int i = 0; i<n; i++){
            cin >> temp;
            q.push(make_pair(i, temp));
            pq.push(temp);
        }

        while(true){
            int idx = q.front().first;
            int v = q.front().second;

            if(v < pq.top()){
                q.push(make_pair(idx, v));
                q.pop();
            }else{
                // print
                q.pop();
                pq.pop();
                cnt++;

                if(idx == m){
                    break;
                }
            }
        }

        cout << cnt << "\n";

        t--;
    }
}