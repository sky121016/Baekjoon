#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

int n;
vector<long long> a;
int l, r;
long long first, second;

long long minVal;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    long long temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    l = 0;
    r = a.size()-1;

    minVal = a[l] + a[r];
    first = a[l];
    second = a[r];

    long long tempSum;

    while(l<r){
        tempSum = a[l] + a[r];
        
        if(abs(tempSum) <= abs(minVal)){
            minVal = tempSum;
            first = a[l];
            second = a[r];
        }


        if(tempSum > 0){
            r--;
        }else{
            l++;
        }
    }

    cout << first << " " << second << "\n";
}

