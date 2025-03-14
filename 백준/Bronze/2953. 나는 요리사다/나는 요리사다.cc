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

int score[6][5];
int winner;
int maxScore;
int total[6];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    for(int i = 1; i<=5; i++){
        for(int j = 1; j<=4; j++){
            cin>>score[i][j];
        }
    }


    for(int i = 1; i<=5; i++){
        for(int j = 1; j<=4; j++){
            total[i] += score[i][j];
        }
    }

    for(int i = 1; i<=5; i++){
        if(maxScore < total[i]){
            maxScore = total[i];
            winner = i;
        }
    }

    cout << winner << " " << maxScore;
}



