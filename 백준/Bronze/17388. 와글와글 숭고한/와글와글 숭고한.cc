
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

int par[3];
int total;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i<3; i++){
        cin >> par[i];
        total += par[i];
    }

    if(total >= 100){
        cout<<"OK";
    }else{
        if(par[0] < par[1] && par[0] < par[2]){
            cout<<"Soongsil";
        }else if(par[1] < par[0] && par[1] < par[2]){
            cout<<"Korea";
        }else if(par[2] < par[0] && par[2] < par[1]){
            cout<<"Hanyang";
        }
    }

}

