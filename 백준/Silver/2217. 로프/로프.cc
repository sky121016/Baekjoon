// 3009
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n;
vector<int> rope;
int MaxElement;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        rope.push_back(temp);
    }

    sort(rope.begin(), rope.end());

    MaxElement = *max_element(rope.begin(), rope.end());

    int tempSum;
    for(int i = 0; i<n; i++){
        tempSum = rope[i] * (n - i);

        if(tempSum > MaxElement){
            MaxElement = tempSum;
        }
    }

    cout << MaxElement;
}
