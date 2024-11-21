#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <map>

using namespace std;

int n;
vector<int> a;
vector<int> sorted;


void BS(int num){
    int l, r, m;

    l = 0;
    r = sorted.size()-1;

    while(l<r){
        m = (l + r) / 2;

        if(num <= sorted[m]){
            r = m;
        }else{
            l = m + 1;
        }
    }
    
    sorted[l] = num;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        a.push_back(temp);
    }

    sorted.push_back(a[0]);
    for(int i = 1; i<n; i++){
        if(sorted.empty() || sorted.back() < a[i]){
            sorted.push_back(a[i]);
        }else{
            BS(a[i]);
        }
    }

    cout << sorted.size();
}
