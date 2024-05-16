// 10775
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

int G;
int P;
vector<int> gate;
vector<int> p;

int cnt;

int findSet(int x){
    if(p[x] == x || p[x] == 0){
        return p[x];
    }

    return p[x] = findSet(p[x]);
}

void makeUnion(int u, int v){
    u = findSet(u);
    v = findSet(v);
    p[u] = v;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> G >> P;

    int temp;
    gate.push_back(0);
    for(int i = 0; i<P; i++){
        cin >> temp;
        gate.push_back(temp);
    }

    p.push_back(0);
    // create Union
    for(int i = 1; i<=G; i++){
        p.push_back(i);
    }

    int v;
    for(int i = 1; i<=P; i++){
        v = findSet(p[gate[i]]); 

        if(v == 0){
            break;
        }

        cnt++;

        makeUnion(v, v-1);
    }



    cout << cnt;
}
