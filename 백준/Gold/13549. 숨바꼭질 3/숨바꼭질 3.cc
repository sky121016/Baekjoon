
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

class Node{
public:
    int x;
    int time;

    void setNode(int x){
        this->x = x;
        time = -1;
    }
};

int n;
int k;

int add;

int dir[3] = {-1, 1, 2};
Node node[101010];

bool canVisit(int nx){
    return (nx >= 0 && nx <= 100000);
}

void bfs(){
    queue<Node> q;
    node[n].time = 0;
    q.push(node[n]);

    int nx;

    Node v;
    while(!q.empty()){
        v = q.front();
        q.pop();
        
        for(int i = 0; i<3; i++){
            if(i == 2){     // 순간이동
                add = 0;
                nx = v.x * dir[i];
            }else{
                add = 1;
                nx = v.x + dir[i];
            }

            if(canVisit(nx) && (node[nx].time > v.time + add || node[nx].time == -1)){
                node[nx].time = v.time + add;
                q.push(node[nx]);
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for(int i = 0; i<=100000; i++){
        node[i].setNode(i);
    }
    
    bfs();

    cout<<node[k].time;
}
