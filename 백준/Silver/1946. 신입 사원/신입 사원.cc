// 3009
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int t;
int n;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  
    int a, b;

    cin >> t;
    while(t > 0){
        vector<pair<int, int> > arr;
        vector<pair<int, int> > newArr;
        cin >> n;

        for(int i = 0; i<n; i++){
            cin >> a >> b;
            arr.push_back(make_pair(a, b));
        }

        sort(arr.begin(), arr.end());
        
        newArr.push_back(arr[0]);

        for(int i = 1; i<n; i++){
            if(newArr.back().first < arr[i].first && newArr.back().second < arr[i].second){
                continue;
            }

            newArr.push_back(arr[i]);
        }

        cout << newArr.size() << "\n";
        t--;
    }
}

