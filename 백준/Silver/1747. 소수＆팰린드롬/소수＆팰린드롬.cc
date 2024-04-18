#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>

using namespace std;

int N;
bool prime[2010101];

bool palindrome(string num){
    int len = num.length();



    for(int i = 0; i<len; i++){
        if(num[i] != num[len-i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    prime[1] = true;
    for(int i = 2; i<=2000000; i++){
        if(!prime[i]){
            for(int j = 2*i; j<2000001; j+=i){
                prime[j] = true;
            }
        }
    }

    for(int i = N; i<=2000000; i++){
        if(palindrome(to_string(i)) && !prime[i]){
            cout<<i;
            return 0;
        }

    }

}

