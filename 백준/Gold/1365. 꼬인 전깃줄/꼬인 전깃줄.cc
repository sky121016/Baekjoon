// 1365
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int n;
vector<int> sorted;

int num[101010];

void BS(int x){
    int l = 0;
    int r = sorted.size() - 1;
    int mid;

    while(l<r){
        mid = (l + r) / 2;

        if(x <= sorted[mid]){
            r = mid;
        }else{
            l = mid+1;
        }
    }

    sorted[l] = x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> num[i];
    }
     

    for(int i = 0; i<n; i++){
        if(sorted.empty() || sorted.back() < num[i]){
            sorted.push_back(num[i]);
        }else{
            BS(num[i]);
        }
    }

    cout << n - sorted.size();
}
