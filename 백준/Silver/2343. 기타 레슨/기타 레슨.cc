// 2343
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int n, m;
int l, r, mid;
int sum;
int a[101010];
int section;
int maxLen;

int BS(){
    l = maxLen;
    r = sum;


    while(l<r){
        section = 0;
        mid = (l + r) / 2;

        // cout << "l = " << l << "\n";
        // cout << "r = " << r << "\n";
        // cout << "mid = " << mid << "\n";
        int temp = mid;

        for(int i = 0; i < n; i++){
            if (temp - a[i] >= 0){
                temp -= a[i];
            }else{
                temp = mid;
                temp -= a[i];
                section++;
            }
        }
        section++;
        // cout << "section " << section << "\n";

        if(section > m){
            l = mid + 1;
        }else{                  // section <= m
            r = mid;
        }
        

    }

    return l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        sum += a[i];
        if (maxLen < a[i]){
            maxLen = a[i];
        }
    }

    cout << BS();
}




