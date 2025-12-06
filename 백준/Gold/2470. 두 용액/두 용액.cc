// 15649
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


int n;
vector<int> a;
int BASE = 1000000000;
int l, r;
int M, m;
int sum = 2000000000;
int tempSum;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    int temp;
    for(int i = 0; i<n; i++){
        cin>>temp;
        a.push_back(temp+BASE);
    }

    sort(a.begin(), a.end());

    l = 0;
    r = n-1;

    while(l<r){
        tempSum = a[l] - BASE + a[r] - BASE;
        if(abs(tempSum) < abs(sum)){
            sum = tempSum;
            M = a[r]-BASE;
            m = a[l]-BASE;
        }

        if(tempSum > 0){
            r--;
        }else{
            l++;
        }
    }
    

    cout<<m<<" "<<M;

}

