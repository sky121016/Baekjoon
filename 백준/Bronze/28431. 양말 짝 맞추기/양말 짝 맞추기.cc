#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

using namespace std;


int visited[11];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int temp;
    for(int i = 0; i<5; i++){
        cin >> temp;
        visited[temp]++;
    }

    for(int i = 0; i<=9; i++){
        if(visited[i] % 2 != 0){
            cout << i;
            break;
        }
    }

}
