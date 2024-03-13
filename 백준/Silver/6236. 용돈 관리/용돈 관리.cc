// 6236
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M;
int money;               // 인출 금액
int arr[100001];         // 하루 사용 금액
int l, r, mid;
int cnt;                 // 인출 횟수

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i<N; i++){
        cin >> arr[i];
        r += arr[i];
    }

    l = *max_element(arr, arr + N);     // 배열에서 가장 큰 값이 K의 최소값

    while(l <= r){
        
        mid = (l + r) / 2;
        money = mid;
        cnt = 1;                        // 맨 처음에 반드시 인출

        for(int i = 0; i<N; i++){
            if(arr[i] > money){
                money = mid;        // 인출
                cnt++;              // 인출 횟수 ++
            }

            money -= arr[i];
        }

        if(cnt <= M){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }

    cout << l;
}

