#include<iostream>
using namespace std;


int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char temp;
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            cin >> temp;
            if(temp == 'F'){
                if(i % 2 == 0 && j % 2 == 0){
                    ans++;
                }else if(i % 2 != 0 && j % 2 != 0){
                    ans ++;
                }
            }
        }
    }

    cout << ans;
}
