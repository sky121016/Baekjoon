// 13904
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

priority_queue < pair<int, int> > pq;
int n;
int a[1010];
int d, w;
int sum;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> d >> w;
        pq.push(make_pair(w, d));
    }


    for(int i = 0; i<n; i++){
        for(int j = pq.top().second; j>0; j--){
            if(a[j]==0){
                a[j] = pq.top().first;
                // cout<<"j "<<j<<" "<<pq.top().first<<"\n";
                break;
            }
        }
        pq.pop();
    }


    for(int i = 1; i<=1001; i++){
        sum+=a[i];
    }
    cout << sum;
}
