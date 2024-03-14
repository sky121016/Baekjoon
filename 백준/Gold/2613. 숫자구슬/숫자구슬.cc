// 2613
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M;
int cnt;
int groupCnt;
int sum;
queue<int> group;
int l, r, mid;
int a[301];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i<N; i++){
        cin >> a[i];
        r += a[i];
    }

    l = *max_element(a, a + N);

    while(l < r){
        mid = (l + r) / 2;

        sum = 0;
        groupCnt = 1;

        for(int i = 0; i<N; i++){
            if(sum + a[i] > mid){
                sum = 0;
                groupCnt++;
            }
            sum += a[i];
        }

        if(groupCnt <= M){
            r = mid;
        }else{
            l = mid + 1;
        }

    }

    sum = 0;
    cnt = 0;

   cout << r << "\n";

    for (int i = 0; i < N; i++){
        if(sum + a[i] > r){
            sum = 0;
            cout << cnt << " ";
            cnt = 0;
            M--;
        }

        sum += a[i];
        cnt++;

        if(N - i == M){
            break;
        }
    }

    while(M > 0){
        cout << cnt << " ";
        cnt = 1;
        M--;
    }

}


