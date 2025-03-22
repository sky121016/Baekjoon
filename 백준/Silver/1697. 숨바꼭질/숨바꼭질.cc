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

int n, k;

int visited[101010];

void bfs(){
    queue<int> q;

    visited[n] = 0;
    q.push(n);

    int v;
    while(!q.empty()){
        v = q.front();
        q.pop();

        if(v == k){
            cout << visited[v];
            return;
        }

        if(v + 1 <= 100000 && visited[v+1] == 0){   
            visited[v + 1] = visited[v] + 1;
            q.push(v + 1);
        }

        if(v - 1 >= 0 && visited[v - 1] == 0){
            visited[v - 1] = visited[v] + 1;
            q.push(v - 1);
        }

        if (2 * v <= 100000 && visited[2 * v] == 0){   
            visited[2 * v] = visited[v] + 1;
            q.push(2 * v);
        }
        
    }
    

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    bfs();
}
