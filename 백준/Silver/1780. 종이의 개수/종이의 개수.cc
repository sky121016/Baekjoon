// 11725
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int map[2200][2200];
int first;
int ans[3];

int check(int n, int y, int x){
    first = map[y][x];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(map[y+i][x+j] != first){
                return -1;
            }
        }
    }

    return first+1;
}

int c;
void paper(int n, int y, int x){

    if(check(n, y, x)>-1){
        c = check(n, y, x);
        ans[c]++;
        return ; 
    }else{
        paper(n/3, y, x);
        paper(n/3, y, x+n/3);
        paper(n/3, y, x+2*(n/3));
        paper(n/3, y+n/3, x);
        paper(n/3, y+n/3, x+n/3);
        paper(n/3, y+n/3, x+2*(n/3));
        paper(n/3, y+2*(n/3), x);
        paper(n/3, y+2*(n/3), x+n/3);
        paper(n/3, y+2*(n/3), x+2*(n/3));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> map[i][j];
        }
    }

    paper(N, 0, 0);

    cout<<ans[0]<<"\n";
    cout<<ans[1]<<"\n";
    cout<<ans[2]<<"\n";
}

