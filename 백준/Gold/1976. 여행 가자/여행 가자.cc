// 1976 여행가자
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int city[201];
int dest[1001];
int N;
int M;

int find(int a){            // root 찾기
    if(a == city[a]){
        return a;
    }

    return find(city[a]);
}

void add(int a, int b){      // root 설정
    a = find(a);
    b = find(b);

    if(a != b){             
        city[b] = a; 
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    
    int temp;

    cin >> N;
    cin >> M;

    for(int i = 1; i<= N; i++){
        city[i] = i;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> temp;
            if(temp == 1){
                add(i, j);
            }
        }
    }

    for(int i = 1; i<=M; i++){        // 여행지
        cin >> dest[i];
    }

    bool ans = true;

    for(int i = 1; i< M; i++){
        if(find(dest[i]) != find(dest[i+1])){
            ans = false;
            break;
        }
    }

    if(ans){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    

}
