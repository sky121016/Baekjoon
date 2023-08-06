// 1715 카드 정렬하기
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > card;
int sum;
int result;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        card.push(temp);
    }


    
    while(card.size() > 1){         // 가장 작은 두 값을 더함
        sum = card.top();           // 첫번째 값
        card.pop();
        sum += card.top();          // 두번째 값 더하기
        card.pop();

        result += sum;
        card.push(sum);             // 더한 값을 큐에 넣기 
    }

    cout << result;
}
