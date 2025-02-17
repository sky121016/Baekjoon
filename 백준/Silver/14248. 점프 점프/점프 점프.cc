#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;


class Node{
public:
    int x;
    bool visited;
    int value;

    void setNode(int x, int v){
        this->x = x;
        visited = false;
        value = v;
    }
};

int n;
Node node[101010];
int cnt;
int s;

void bfs(){
    queue<Node> q;
    node[s].visited = true;
    q.push(node[s]);
    
    cnt++;
    int lx, rx;

    Node v;
    while(!q.empty()){
        v = q.front();
        q.pop();

        int jump = v.value;

        // left
        lx = v.x - jump;
        if (lx > 0 && !node[lx].visited){
            node[lx].visited = true;
            cnt++;
            q.push(node[lx]);
        }

        rx = v.x + jump;
        if(rx <= n && !node[rx].visited){
            node[rx].visited = true;
            cnt++;
            q.push(node[rx]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int temp;
    for(int i = 1; i<=n; i++){
        cin >> temp;
        node[i].setNode(i, temp);
    }

    cin >> s;

    bfs();

    cout << cnt;
}
