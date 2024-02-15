// 1339
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

vector<char> v[27];
int n;

void preorder(char node){
    if(node == '.'){
        return;
    }
    cout<<node;
    preorder(v[node-'A'][0]);
    preorder(v[node-'A'][1]);
}

void inorder(char node){
    if (node == '.'){
        return;
    }

    inorder(v[node-'A'][0]);
    cout<<node;
    inorder(v[node-'A'][1]);
}

void postorder(char node){
    if (node == '.'){
        return;
    }

    postorder(v[node-'A'][0]);
    postorder(v[node-'A'][1]);
    cout<<node;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    char node, left, right;

    for(int i = 0; i<n; i++){
        cin >> node >> left >> right;


        v[node-'A'].push_back(left);
        v[node-'A'].push_back(right);

    }

    // pre
    preorder('A');
    cout<<'\n';
    // in
    inorder('A');
    cout<<"\n";
    // post
    postorder('A');

}




