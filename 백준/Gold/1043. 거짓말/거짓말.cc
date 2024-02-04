// 1374
#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

// check
// makeUnion
// find

int n, m;
int tempPeople;
int tempNum;
int knowCnt;
int p[51];
int goParty;
bool cantLie;
bool party[51];

vector<int> a[51];
bool know[51];

int Find(int x){
    if(p[x] == x){
        return p[x];
    }else{
        return p[x] = Find(p[x]);
    }
}

void makeUnion(int x, int y){
    int px = Find(x);
    int py = Find(y);

    if(know[px] > know[py]){      // x가 알아
        p[py] = p[px];
    }else{
        p[px] = p[py];
    }


}

bool check(int x, int y){
    int px = Find(x);
    int py = Find(y);
    if(px == py){
        return true;
    }else{
        return false;
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> knowCnt;

    int k;

    for(int i = 1; i<=n; i++){
        p[i] = i;
    }

    for(int i = 0; i<knowCnt; i++){
        cin >> k;
        know[k] = true;
    }



    for(int i = 0; i<m; i++){
        cin >> tempPeople;

        for(int j = 0; j<tempPeople; j++){
            cin >> tempNum;
            a[i].push_back(tempNum);
        }

    }

   

    for(int i = 0; i<m; i++){
        for(int j = 0; j<a[i].size()-1; j++){
            makeUnion(a[i][j], a[i][j+1]);
        }
    }


    goParty = m;

    int A, B;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<a[i].size(); j++){
            if(know[Find(a[i][j])]){
                goParty--;
                break;
            }
        }
    }

    cout << goParty;


}


