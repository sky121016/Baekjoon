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
vector<pair<int,int> > line;
vector<int> LIS;
vector<int> P;
int l, r, m;
vector<int> ans;


void BS(int num){
    if(LIS.size() == 0){
        LIS.push_back(num);
        P.push_back(0);
    }else if(LIS[LIS.size()-1] < num){
        LIS.push_back(num);
        P.push_back(LIS.size()-1);
    }else{
        l = 0;
        r = LIS.size()-1;

        while(l<r){
            m = (l + r) / 2;
            
            if(num <= LIS[m]){
                r = m;
            }else{
                l = m + 1;
            }
        }

        LIS[l] = num;
        P.push_back(l);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;


    int a, b;
    for(int i = 0; i<n; i++){
        cin >> a >> b;
        line.push_back(make_pair(a, b));
    }
    
    sort(line.begin(), line.end());

    for(int i = 0; i<line.size(); i++){
        BS(line[i].second);
    }



    int cnt = LIS.size()-1;

    for(int i = n-1; i>=0; i--){
        if(P[i] == cnt){
            cnt--;
            continue;
        }
        ans.push_back(line[i].first);
    }

    cout << n - LIS.size() << "\n";

    for(int i = ans.size()-1; i>=0; i--){
        cout << ans[i] << "\n";
    }
}
