// 1655 가운데를 말해요
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

priority_queue<int> Max;
priority_queue<int, vector<int>, greater<int> > Min;
int N;
int cnt;

int main(){
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    cin >> N;
    int a;
    int idx = 0;
    for(int i = 0; i<N; i++){
        cin >> a;

        if(Max.size() == Min.size()){
            Max.push(a);
        }else{
            Min.push(a);
        }

        if(!Max.empty() && !Min.empty() && Max.top() > Min.top()){
            int M = Max.top();
            int m = Min.top();
            Max.pop();
            Min.pop();
            Max.push(m);
            Min.push(M);
        }

        cout<<Max.top()<<"\n";
    }
}


