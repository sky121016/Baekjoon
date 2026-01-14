// 11053
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
int x, y;
int k;
int map[21][21];
int cmd;
int dice[6];

int dir[5][2] = {{}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void move(int cmd){
    int temp;
    if(cmd == 1){       //  ->
        temp = dice[4];
        dice[4] = dice[0];
        dice[0] = dice[5];
        dice[5] = dice[2];
        dice[2] = temp;
    }else if(cmd == 2){ // <-
        temp = dice[5];
        dice[5] = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[2];
        dice[2] = temp;
    }else if(cmd == 3){ // 위


           temp = dice[3];
        dice[3] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[0];
        dice[0] = temp;
    }else if(cmd == 4){ // 아래
             temp = dice[0];
        dice[0] = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[3];
        dice[3] = temp;
    }

            
    // for(int i = 0; i<6; i++){
    //     cout<<dice[i]<<" ";
    // }
    // cout<<"\n";

}


bool canVisit(int ny, int nx){
    return (ny >= 0 && ny < n && nx >= 0 && nx < m);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> y >> x >> k;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
        }
    }

    while(k > 0){
        cin >> cmd;
    
        
        int ny = y + dir[cmd][0];
        int nx = x + dir[cmd][1];
        
        if(canVisit(ny, nx)){  
            move(cmd);
            
            if(map[ny][nx] == 0){
                map[ny][nx] = dice[0];
            }else{
                dice[0] = map[ny][nx];
                map[ny][nx] = 0;
            }
            
            // for(int i = 0; i<6; i++){
            //     cout<<dice[i]<<" ";
            // }
            // cout<<"\n";


            cout << dice[2] << "\n";

            y = ny;
            x = nx;
    
        }
        k--;
    }
}

