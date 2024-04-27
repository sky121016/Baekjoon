// 17136
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>

using namespace std;

int map[11][11];
int Min;
int paperCnt[5] = {5, 5, 5, 5, 5};


bool canPut(int y, int x, int size){
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){

            if(map[y+i][x+j] == 0){
                return false;
            }
        }
    }
    return true;
}


void setPaper(int y, int x, int size, int put){
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            // cout<<"put "<<y+i<<" "<<x+j<<" size"<<size<<"\n";
            map[y+i][x+j] = put;
        }
    }


}

bool done(){
    
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            if(map[i][j] == 1){
                return false;
            }
        }
    }
    return true;
}

void paper(int cnt){

    if(Min <= cnt){
        return;
    }

    if(done()){
        Min = min(Min, cnt);
        return;
    }

    int ny, nx;

    bool flag = false;
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            if(map[i][j] == 1){
                ny = i;
                nx = j;
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
    }

    // cout<<ny<<" "<<nx<<"\n";


    for(int size = 5; size>0; size--){
        if(nx + size > 10 || ny + size > 10 ){
            continue;
        }
        if(paperCnt[size-1] == 0){
            continue;
        }

        if (canPut(ny, nx, size)){
            paperCnt[size-1]--;
            setPaper(ny, nx, size, 0);

            paper(cnt + 1);

            paperCnt[size-1]++;
            setPaper(ny, nx, size, 1);
        }
    }

     

    // if(Min <= cnt){
    //     return;
    // }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            cin >> map[i][j];
        }
    }

    Min = 100;

    paper(0);

    if(Min == 100){
        cout<<"-1";
    }else{
        cout<<Min;
    }
}

