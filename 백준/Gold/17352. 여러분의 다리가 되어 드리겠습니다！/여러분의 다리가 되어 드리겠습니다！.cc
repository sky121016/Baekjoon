// 17265
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n;
int parent[301010];


int find(int x){
    if(parent[x] == x){
        return x;
    }

    return parent[x] = find(parent[x]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;

    cin >> n;

    for(int i = 1; i<=n; i++){
        parent[i] = i;
    }

    for (int i = 0; i < n - 2; i++){
        cin >> a >> b;
        a = find(a);
        b = find(b);
        parent[b] = a;
    }


    int first, second;
    first = 1;
    for(int i = 2; i<=n; i++){
        if(find(first) != find(i)){
            second = i;
            break;
        }
    }




    cout << parent[first] << " " << parent[second];
}

