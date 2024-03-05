// 1057
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;

int n;
double jimin;
double hansu;
int cnt;


int main(){
    cin>>n;
    cin>>jimin>>hansu;


    while(jimin>0 && hansu>0){
        if(abs(jimin-hansu) == 1 && (int(min(jimin, hansu)) % 2 == 1)){   // 지민과 한수 인덱스의 차 = 1 && 둘 중 작은 값이 홀수 -> 인접
            cnt++;
            break;
        }else{
            jimin = round(jimin/2);
            hansu = round(hansu/2);
            cnt++;
        }

    }


    if(cnt == 0){
        cout<<"-1";
    }else{
        cout<<cnt;
    }

    
}