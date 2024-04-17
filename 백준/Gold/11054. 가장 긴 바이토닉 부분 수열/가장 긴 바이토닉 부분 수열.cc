#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


int N;
int a[1010];
int increase[1010];
int decrease[1010];
int Ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1; i<=N; i++){
        cin >> a[i];
    }

    for(int i = 1; i<=N; i++){
        for(int j = 0; j<i; j++){
            if(a[j] < a[i]){
                increase[i] = max(increase[j]+1, increase[i]);
            }
        }
    }
    
    for(int i = N; i>0; i--){
        for(int j = N+1; j>i; j--){
            if(a[j] < a[i]){
                decrease[i] = max(decrease[j] + 1, decrease[i]);
            }
        }
    }

    int temp = 0;
    for(int i = 1; i<=N; i++){
        temp = increase[i] + decrease[i];
        if(temp > Ans){
            Ans = temp;
        }
    }

    cout << Ans - 1;
}



