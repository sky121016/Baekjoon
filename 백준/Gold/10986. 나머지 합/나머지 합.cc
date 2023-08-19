// 10986
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M;
long long sum[1000001];
long long mod[1001];
long long cnt;

long long C(long long n){
    if(n < 2){
        return 0;
    }else{
        return (n * (n - 1)) / 2;       // nC2 = n! / ((n-2)! * 2!) = n * (n-1) / 2
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    long long a;
    for(int i = 1; i<=N; i++){
        cin >> a;
        sum[i] = sum[i-1] + a;

        if(sum[i] % M == 0){
            cnt ++;
        }
        mod[sum[i] % M]++;
    }


    for(int i = 0; i<M; i++){
        cnt += C(mod[i]);
    }

    cout << cnt;
}

