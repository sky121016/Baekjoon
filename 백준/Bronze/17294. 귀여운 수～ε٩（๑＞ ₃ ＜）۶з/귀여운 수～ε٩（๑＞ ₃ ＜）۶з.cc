#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

using namespace std;

long long n;
int gap;
bool ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    ans = true;

    long long temp = n;
    while(n /10 > 0){
        int a, b;
        a = n % 10;
        n /= 10;

        b = n % 10;
        if(temp / 10 == n){
            gap = a - b;
        }

        
        if(gap != a-b){
            ans = false;
            break;
        }
        
        gap = a - b;

    }

    if(ans){
        cout<<"◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
    }else{
        cout<<"흥칫뿡!! <(￣ ﹌ ￣)>";
    }

}


