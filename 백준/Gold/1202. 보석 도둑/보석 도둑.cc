// 3009
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n, k;
vector<pair<int, int> > mv;
vector<long long> c;
priority_queue<int> pq;

long long sum;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    int a, b;
    for(int i = 0; i<n; i++){
        cin >> a >> b;
        mv.push_back(make_pair(a, b));
    }

    sort(mv.begin(), mv.end());

    int temp;
    for(int i = 0; i<k; i++){
        cin >> temp;
        c.push_back(temp);
    }

    sort(c.begin(), c.end());

    int idx = 0;

    for(int i = 0; i<k; i++){
        for(int j = idx; j<n; j++){
            if(mv[j].first <= c[i]){
                pq.push(mv[j].second);
                idx++;
            }else{
                break;
            }
        }

        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum;
}
