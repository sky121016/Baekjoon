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

int n;
int adj[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> adj[i][j];
        }
    }



    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(adj[i][k] && adj[k][j]){
                    adj[i][j] = 1;
                }
            }
        }
    }


    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(adj[i][j] != 0){
                cout << 1 << " ";
            }else{
                cout << 0 << " ";
            }
        }
        cout<<"\n";
    }

}
