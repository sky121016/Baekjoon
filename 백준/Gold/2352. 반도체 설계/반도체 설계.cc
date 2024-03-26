// 2839
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;
vector<int> lis;
int a[40001];
int p[40001];
int ans;

int l, r, mid;

void BS(int num){

    if(lis.size() == 0 || lis[lis.size()-1] < num){
        lis.push_back(num);
    }else{
        
        l = 0;
        r = lis.size() - 1;

        while(l < r){
            mid = (l + r) / 2;
            if(num < lis[mid]){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        lis[l] = num;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    
    for(int i = 1; i<=n; i++){
        BS(a[i]);    
    }

    cout << lis.size();
}
