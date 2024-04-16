#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int N;
int nodes[10001][2];
vector<int> level[10001];
int cnt;
bool in[10001];
int root;
int maxL;
int ansLevel;
int ansWidth;

void findRoot(){
    for (int i = 1; i <= N; i++){
        if(!in[i]){
            root = i;
        }
    }
}

void visit(int node, int l){
    level[l].push_back(cnt);
    cnt++;
    if(maxL < l){
        maxL = l;
    }
}

void inorder(int node, int l){

    if(nodes[node][0] != -1){
        inorder(nodes[node][0], l + 1);
    }
    visit(node, l);
    if (nodes[node][1] != -1){
        inorder(nodes[node][1], l + 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int temp, left, right;
    for(int i = 0; i<N; i++){
        cin >> temp >> left >> right;
        nodes[temp][0] = left;
        nodes[temp][1] = right;
        if(left != -1){
            in[left] = true;
        }
        if(right != -1){
            in[right] = true;
        }
    }

    cnt = 1;
    findRoot();
    inorder(root, 1);


    int tempW = 0;
    for(int i = 1; i<=maxL; i++){
        tempW = *max_element(level[i].begin(), level[i].end()) - *min_element(level[i].begin(), level[i].end()) + 1;
        if(ansWidth < tempW){
            ansWidth = tempW;
            ansLevel = i;
        }
    }

    cout << ansLevel << " " << ansWidth;
}
