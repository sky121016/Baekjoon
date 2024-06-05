// 1197
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>

using namespace std;


int n;
int a[9];
int sum;
int visited[9];
int tempMax;

void maxsum(int k, int cnt){
    if(cnt == n){
        if(tempMax <= sum){
            tempMax = sum;
        }
        return;
    }

    for(int i = 0; i<n; i++){
        if(i != k && !visited[i]){
            visited[i] = true;
            sum += abs(a[k]-a[i]);
            maxsum(i, cnt+1);
            visited[i] = false;
            sum -= abs(a[k]-a[i]);
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        visited[i] = true;
        maxsum(i, 1);
        visited[i] = false;
    }


    cout<<tempMax;
}

