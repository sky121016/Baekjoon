#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int t;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t > 0){
        cin >> n;

        if((n+1) % ((n)%100) == 0){
            cout<<"Good\n";
        }else{
            cout << "Bye\n";
        }

        t--;
    }
}

