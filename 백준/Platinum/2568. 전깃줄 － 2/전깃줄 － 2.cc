

// 2568
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int N;
vector<pair<int, int> > LIS;
vector<pair<int, int> > a;
bool line[500001];
int l, r, mid;
vector<int> p;
vector<int> ans;

void BS(int n){
    if(LIS.size() == 0){
        LIS.push_back(make_pair(a[n].first, a[n].second));
        p.push_back(0);
    }else if(a[n].second > LIS[LIS.size() - 1].second){
        LIS.push_back(make_pair(a[n].first, a[n].second));

        p.push_back(LIS.size()-1);
    }else{
        l = 0;
        r = LIS.size() - 1;

        while(l < r){
            mid = (l + r) / 2;

            if (a[n].second < LIS[mid].second){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        LIS[l].first = a[n].first;
        LIS[l].second = a[n].second;
        p.push_back(l);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int x, y;
    for(int i = 0; i<N; i++){
        cin >> x >> y;
        a.push_back(make_pair(x, y));
    }


    sort(a.begin(), a.end());


    for(int i = 0; i<N; i++){
        BS(i);
    }

    cout << N - LIS.size() << "\n";

    int cnt = LIS.size() - 1;

    for(int i = N-1; i>=0; i--){
        if(p[i] == cnt){
            cnt --;
            continue;
        }
        ans.push_back(a[i].first);
    }

  
    for(int i = ans.size()-1; i>=0; i--){
        cout << ans[i] << "\n";
    }



}


