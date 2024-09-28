// 13398
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdlib>
using namespace std;



int n;
int card[5];

int main(){
    cin >> n;

    string f;
    int cnt;
    for(int i = 0; i<n; i++){
        cin >> f >> cnt;
        if(f == "STRAWBERRY"){
            card[0] += cnt;
        }else if(f == "BANANA"){
            card[1] += cnt;
        }else if(f == "LIME"){
            card[2] += cnt;
        }else{
            card[3] += cnt;
        }
    }


    string ans = "NO";

    for(int i = 0; i<5; i++){
        if(card[i] == 5){
            ans = "YES";
        }
    }

    cout<<ans;
}
