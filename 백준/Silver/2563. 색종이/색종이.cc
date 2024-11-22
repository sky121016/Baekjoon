// 2563
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

bool colored[101][101];
int n;
int x, y;

int cnt;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> y >> x;

        for(int j = 0; j<10; j++){
            for(int k = 0; k<10; k++){
                if(!colored[y+j][x+k]){
                    cnt ++ ;
                    colored[y+j][x+k] = true;
                }
            }
        }
    }

    cout<<cnt;
}


