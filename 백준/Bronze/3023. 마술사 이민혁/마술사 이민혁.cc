#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int r, c;
int a, b;

char map[60][60];
char ans[110][110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c; j++){
            cin >> map[i][j];
        }
    }

    
    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c; j++){
            ans[i][j] = map[i][j];
        }
    }
    
    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c; j++){
            ans[i][j+c] = map[i][c - j + 1];
        }
    }
 
    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=2*c; j++){
            ans[2 * r - i + 1][j] = ans[i][j];
        }
    }

    cin >> a >> b;

    if(ans[a][b] == '.'){
        ans[a][b] = '#';
    }else{
        ans[a][b] = '.';
    }

    for(int i = 1; i<=2*r; i++){
        for(int j = 1; j<=2*c; j++){
            cout<<ans[i][j];
        }
        cout<<"\n";
    }

    

}