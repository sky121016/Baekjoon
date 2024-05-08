// 1516
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>

using namespace std;

int n;
int buildTime[501];
vector<int> in[501];
int inCnt[501];
vector<int> out[501];
int totalTime[501];

int findInZero(){
    for(int i = 1; i<= n; i++){
        if(inCnt[i] == 0){
            return i;
        }
    }

    return 0;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int temp = 0;

    for(int i = 1; i<=n; i++){
        cin >> buildTime[i];
        int cnt = 0;

        while(1){
            cin >> temp;
            if(temp == -1){
                break;
            }
            in[i].push_back(temp);
            out[temp].push_back(i);
            cnt++;
        }

        inCnt[i] = cnt;

    }
    
    for(int i = 0; i<n; i++){
        int b = findInZero();
        int t = 0;

        // time 결정
        if(in[b].size() == 0){
            totalTime[b] = buildTime[b];
        }else{
            for(int j = 0; j<in[b].size(); j++){
                t = totalTime[in[b][j]] + buildTime[b];
                totalTime[b] = max(totalTime[b], t);
            }
        }
        // Out 찾아서 개수 -1
        for(int j = 0; j<out[b].size(); j++){
            inCnt[out[b][j]]--;
        }

        inCnt[b] = -1;


    }

    for(int i = 1; i<=n; i++){
        cout<<totalTime[i]<<"\n";
    }

}



