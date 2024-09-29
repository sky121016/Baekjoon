// 2108 통계학

#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;

int average(int* num, int n){
    double sum = 0;
    for(int i = 0; i<n; i++){
        sum += num[i];
    }
    return round(sum/n);
}

int median(int* num, int n){
    sort(num,num+n);
    return num[n/2];
}

int mode(int* num, int n){
    int count[8001]={0};
    int max=0;                          // max Count
    int maxIndex=0;                   // max data Index 0~8000


    for(int i = 0; i<n; i++){
        count[num[i]+4000]++;
    }


    for(int j = 0; j<8001; j++){
        if(count[j] > max){
            max = count[j];
            maxIndex = j;
        }      
    }


    int result = maxIndex;

    for(int i = maxIndex+1; i<8001; i++){
        if(count[i] == max){
            result = i;
            break;
        }
    }

    return result-4000;

}

int range(int* num, int n){
    sort(num,num+n);
    int result = num[n-1]-num[0];
    return result;
}

int main(){
    int n;
    scanf("%d", &n);

    int num[500000];

    for(int i = 0; i<n; i++){
        scanf("%d", &num[i]);
    }

    printf("%d\n",average(num,n));
    printf("%d\n",median(num,n));
    printf("%d\n",mode(num,n));
    printf("%d\n",range(num,n));


}

