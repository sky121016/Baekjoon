// 2812 크게만들기
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

stack<int> s;
int N, K;
int popCnt;
int pushCnt;
vector<char> a;
vector<int> ans(505050);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    char temp;
    for(int i = 0; i < N; i++){
        cin >> temp;
        a.push_back(temp);
    }


    for (int i = 0; i < N; i++){

        if(!s.empty() && pushCnt == N-K && s.top() < (a[i] - '0')){
            s.pop();
            s.push(a[i] - '0');
            continue;
        }
        if(s.empty() || popCnt == K){
            s.push(a[i] - '0');
            pushCnt++;
            continue;
        }


        if(pushCnt < N-K){

            while(!s.empty() && s.top() < (a[i] - '0') && popCnt < K){
                s.pop();
                popCnt++;
                pushCnt--;
            }

            s.push(a[i] - '0');
            pushCnt++;
        }
   

 

    }
    
    

    for(int i = N-K-1; i>=0; i--){
        ans[i] = s.top();
        s.pop();
    }

    for(int i = 0; i<N-K; i++){
        cout<<ans[i];
    }
}
