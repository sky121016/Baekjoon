// 2448 별찍기
#include<iostream>
#include<vector>
using namespace std;

int n;
char arr[3][5] = {
    {' ',' ','*',' ',' '},
    {' ','*',' ','*',' '},
    {'*','*','*','*','*'},
};

char map[3500][6500];


void star(int num, int y, int x){
    if(num == 3){
        for(int i = 0; i<3; i++){
            for(int j = 0; j<5; j++){
                map[y+i][x+j] = arr[i][j];

            }
        }
        return;
    }
    star(num / 2, y, x + num / 2);
    star(num / 2, y + num / 2, x);
    star(num / 2, y + num / 2, x + num);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;

    star(n, 0, 0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n * 2 - 1; j++){
            if(map[i][j] == '*'){
                cout << map[i][j];
            }else{
                cout << ' ';
            }
        }
        cout << "\n";
    }


}
