// 2503 숫자 야구
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Question{
public:
    string num;
    int strike;
    int ball;

};

// string question;
int n;
int cnt;
Question Q[101];
vector<string> Num;

int s, b;

bool check(string num){

    for(int i = 0; i<n; i++){                       // 문제 수 만큼
        s = 0;  
        b = 0;
        for(int j = 0; j<3; j++){                   // 문제의 각 자리 수 index
            for(int k = 0; k<3; k++){               // num(123 ~ 987)의 각 자리수 index 
                if(Q[i].num[j] == num[k]){      
                    if(j == k){                     // strike
                        s++;
                    }else{                          // ball
                        b++;
                    }
                    break;                          // 서로 다른 3개의 수라서 s/b 나왔으면 더 비교할 필요 x
                }
            }
        }
        if(Q[i].strike != s || Q[i].ball != b){     // s b 하나라도 다르면 false 반환
            return false;
        }
    }
    
    return true;                                    // 문제들과 s b 일치
}

void game(){

    for(int i = 0; i<Num.size(); i++){          // 123 ~ 987 넣어줌
        if(check(Num[i])){
            cnt++;
        }
    }

    cout<<cnt;

}


int main(){
    cin>>n;


    for(int i = 0; i<n; i++){
        cin>>Q[i].num;
        cin>>Q[i].strike;
        cin>>Q[i].ball;
    }


    for(int i = 1; i<=9; i++){                      // 서로 다른 수 3개로 이루어진 숫자 찾기
        for(int j = 1; j<=9; j++){
            for(int k = 1; k<=9; k++){
                if(i == j || i == k || j == k){
                    continue;
                }
                
                string temp = to_string(i*100 + j*10 + k);
                Num.push_back(temp);
            }
        }
    }

    game();

}