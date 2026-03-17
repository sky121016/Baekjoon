// 11053
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<int> x;
int n, c;
int maxDiff;


bool isTrue(int d){
    int section = 1;
    int prevX = x[0];

    for(int i = 1; i<n; i++){
        if(x[i] - prevX >= d){
            section++;
            prevX = x[i];
        }
    }


    return section >= c;
}


void BS(){
    int l, r, mid;

    
    l = 1;
    r = maxDiff;


    int ans = 0;
    
    while(l<=r){
        mid = (l + r) / 2;

        if(isTrue(mid)){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }

    cout << ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int temp;

    cin >> n >> c;

    for(int i = 0; i<n; i++){
        cin>>temp;
        x.push_back(temp);
    }

    sort(x.begin(), x.end());

    int minValue = *min_element(x.begin(), x.end());
    int maxValue = *max_element(x.begin(), x.end());

    maxDiff = maxValue - minValue;


    BS();
}
