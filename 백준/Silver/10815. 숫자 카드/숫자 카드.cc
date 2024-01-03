// 10815
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> myCard;
vector<int> findCard;

int find(int num, int l, int r){
    int mid;

    while(l<=r){
        mid = (l + r) / 2;
        
        if(myCard[mid] < num){
            l = mid + 1;
        }else if(myCard[mid] > num){
            r = mid - 1;
        }else{
            return 1;
        }
    }

    if(num == myCard[mid]){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int num;
    for(int i = 0; i<n; i++){
        cin >> num;
        myCard.push_back(num);
    }

    sort(myCard.begin(), myCard.end());

    cin >> m;

    for(int i = 0; i<m; i++){
        cin >> num;
        cout<<find(num, 0, n-1)<<' ';

    }


}