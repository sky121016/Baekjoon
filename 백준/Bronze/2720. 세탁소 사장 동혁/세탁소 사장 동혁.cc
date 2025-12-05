// 10815
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int t;
int c;

int coin[4]={25, 10, 5, 1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t>0){
        int cnt[4] = {0, 0, 0, 0};
        cin >> c;
        int i = 0;
        
        while(c>0){
            if(c - coin[i] >= 0){
                c -= coin[i];
                cnt[i]++;
            }else{
                i++;
            }
        }

    
        for(int j = 0; j<4; j++){
            cout<<cnt[j]<<" ";
        }
        cout<<"\n";

        t--;
    }
}