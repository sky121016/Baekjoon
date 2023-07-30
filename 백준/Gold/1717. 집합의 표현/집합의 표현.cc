// 1717 집합의 표현
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int arr[1000001];

int find(int a){
    if(arr[a] == a){                    // 내가 루트
        return a;
    }

    return arr[a] = find(arr[a]);       // 루트 찾기
}

void add(int a, int b){
    a = find(a);            // 루트 값 받아오기
    b = find(b);

    if(a != b){             
        arr[b] = a;         // 집합 합치기
    }
}

void check(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b){             // 같은 집합에 포함
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> m;

    for(int i = 0; i<=n; i++){          // 초기화
        arr[i] = i;
    }

    int op;
    int a, b;

    for(int i = 0; i<m; i++){
        cin >> op >> a >> b;
        if(op == 0){
            add(a, b);
        }else if(op == 1){
            check(a, b);
        }
    }
}
