// 20040
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int p[1010101];
bool cycle;
bool done;
int ans;

int Find(int x){
    if (p[x] == x){
        return p[x];
    }
    
    return p[x] = Find(p[x]);
}

void Union(int x, int y){
    int px;
    int py;
    px = Find(x);
    py = Find(y);

    if(px != py){
        p[py] = px;
    }
    
}

bool check(int x, int y){
    x = Find(x);
    y = Find(y);

    if (x == y){
        return true;
    }
    return false;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i<n; i++){
        p[i] = i;
    }

    int x, y;

    for(int i = 1; i<=m; i++){
        cin >> x >> y;
        if(!check(x, y)){
            Union(x, y);
        }else{
            if(!done){
                ans = i;
                cout << ans << "\n";
                done = true;
            }
        }
    
    }

    if(!done){
        cout << ans<<"\n";
    }
}

