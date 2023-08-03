// 14888 연산자
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> num;
vector<int> ans;
int operators[4];       // 연산자 개수
int result;             

int calculate(int op, int a, int b){
    if(op == 0){               
        return a+b;
    }else if(op == 1){
        return a-b;
    }else if(op == 2){
        return a*b;
    }else{
        return a/b;
    }
}


void dfs(int r, int index, int cnt){
    if(cnt == 1){                       // 답 저장
        ans.push_back(r);
        return;
    }



    for(int i = 0; i<4; i++){
        if(operators[i] > 0){
            result = calculate(i, r, num[index + 1]);
            operators[i] --;                            // 연산자 개수 하나 빼기

            dfs(result, index + 1, cnt - 1);            // result에 index+1번째 수를 연산

            operators[i] ++;                            // 연산자 개수 하나 다시 더해주기
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        num.push_back(temp);
    }
    
    for(int i = 0; i<4; i++){
        cin >> operators[i];
    }

    dfs(num[0], 0, n);

    cout<<*max_element(ans.begin(), ans.end())<<endl;
    cout<<*min_element(ans.begin(), ans.end())<<endl;
}