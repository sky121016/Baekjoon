// 12015
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>

using namespace std;

int n;
vector<int> v;
int l, r, m;
int num[1010101];

void BS(int a){
    l = 0;
    r = v.size() - 1;
    
    while(l < r){
        m = (l + r) / 2;

        if(a <= v[m]){
            r = m;
        }else{
            l = m + 1;
        }
    }
    v[l] = a;
    
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
        
        if(v.empty() || v.back() < num[i]){
            v.push_back(num[i]);
        }else{
            BS(num[i]);
        }
    }
    cout << v.size();
}

