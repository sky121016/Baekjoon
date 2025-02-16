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

        if(n == 1){
            cout<<"#\n\n";
        }else{

            for (int i = 0; i < n; i++)
            {
                cout << "#";
            }
            cout << "\n";

            for (int i = 0; i < n - 2; i++)
            {
                cout << "#";
                for (int j = 0; j < n - 2; j++)
                {
                    cout << "J";
                }
                cout << "#\n";
            }

            for (int i = 0; i < n; i++)
            {
                cout << "#";
            }
            cout << "\n\n";
        }

        t--;
    }
}


