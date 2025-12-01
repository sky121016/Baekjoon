// 3273
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, x;
int cnt;
vector<int> num;
int sum;

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

    int l = 0, r = n - 1;

    sort(num.begin(), num.end());

    cin >> x;


    while(l<r){
        sum = num[l] + num[r];
        if(sum == x){
            cnt++;
            l++;
            r--;
        }else if(sum < x){
            l++;
        }else{
            r--;
        }
    }

    cout << cnt;
}
