// 2250 트리
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;

class Node{
public:
    int num;
    int left;
    int right;
    int width;

    void setNode(int num, int l, int r){
        this->num = num;
        left = l;
        right = r;
        width = 0;
    }
};


Node node[10001];
vector<int> depth[10001];
int maxWidth[10001];
int cnt;                // 열 번호
int level = 1;         
int maxD;               // 최대 레벨
int ansLevel;
int ansWidth;
bool isNotRoot[10001];     // 루트 노드 찾기
int root;

void visit(int num){
    cnt++;
    node[num].width = cnt;
    depth[level].push_back(cnt); 
    if(maxD < level){
        maxD = level;
    }

}

void inorder(int num){
    if(num == -1){
        return;
    }
    level++;
    inorder(node[num].left);
    level--;
    
    visit(num);
    
    level++;
    inorder(node[num].right);
    level--;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int num, left, right;
    for(int i = 0; i<n; i++){
        cin >> num >> left >> right;
        node[num].setNode(num, left, right);
        if(left != -1){
            isNotRoot[left] = 1;
        }
        if(right != -1){
            isNotRoot[right] = 1;
        }
    }

    for(int i = 1; i<=n; i++){
        if(isNotRoot[i] != 1){
            root = i;
        }
    }

    inorder(root);


    for(int i = 1; i<=maxD; i++){
        maxWidth[i] = *max_element(depth[i].begin(), depth[i].end()) - *min_element(depth[i].begin(), depth[i].end()) + 1;

        if(ansWidth < maxWidth[i]){
            ansLevel = i;
            ansWidth = maxWidth[i];
        }
    }

    cout << ansLevel << " " << ansWidth;
}

