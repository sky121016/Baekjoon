// 2109
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
int a[1010101];
vector<int> R;

void BS(int num){
    int l, r;
    int m;

    if(R.size() == 0 || R[R.size()-1]<num){
        R.push_back(num);
    }else{
        l = 0;
        r = R.size() - 1;


        while(l<r){
            m = (l + r) / 2;
            if(num <= R[m]){
                r = m;
            }else{
                l = m + 1;
            }
        }

        R[l] = num;
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

    cout << R.size();
}

