// 10815
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
int target;

vector<int> A;


void BS(int t){
    int l, r;

    l = 0;
    r = n-1;
    int mid = (l+r)/2;
    while(l<r){
        mid = (l+r)/2;

        if(t<=A[mid]){
            r = mid;
        }else{
            l = mid+1;
        }
    }

    if(A[l] == t){
        cout<<"1 ";
        return;
    }
    cout << "0 ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        A.push_back(temp+10000000);
    }

    sort(A.begin(), A.end());

    cin >> m;
    
    for(int i = 0; i<m; i++){
        cin >> target;
        BS(target+10000000);
    }
}
