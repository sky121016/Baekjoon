// 2616
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int n;
int s;
int a[21];
// int temp;
bool visited[21];
int cnt;

void sum(int index, int size, int temp){

    if(temp == s && size != 0){
        cnt ++;
    }

    for(int i = index; i<n; i++){

        if(!visited[i]){
            visited[i] = true;
            sum(i, size + 1, temp + a[i]);
            visited[i] = false;
        }

    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s;

    for(int i = 0; i<n; i++){
        cin >> a[i];
    }


    sum(0, 0, 0);

    cout << cnt;
}




