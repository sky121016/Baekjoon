// 1325
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>

using namespace std;

int a, b;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){
        cin >> a >> b;

        if(a == 0 && b == 0){
            break;
        }

        if(b%a == 0){
            cout<<"factor\n";
        }else if(a%b == 0){
            cout<<"multiple\n";
        }else{
            cout<<"neither\n";
        }
    }


}
