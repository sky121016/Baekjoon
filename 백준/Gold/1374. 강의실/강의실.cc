// 1374
#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > pq;
vector<pair<int, int> > v;
int maxCnt;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int c, s, e;
    for(int i = 0; i<n; i++){
        cin >> c >> s >> e;
        v.push_back(make_pair(s, e));
    }

    sort(v.begin(), v.end());



    for(int i = 0; i<n; i++){
        if(pq.empty()){
            maxCnt++;
        }else{
            if(pq.top()<=v[i].first){
                pq.pop();
            }else{
                maxCnt++;
            }
        }
        pq.push(v[i].second);
    }

    cout << maxCnt;
}

