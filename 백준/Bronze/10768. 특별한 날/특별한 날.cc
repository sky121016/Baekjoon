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

int m, d;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> d;

    if(m<2){
        cout<<"Before";
    }else if(m == 2){
        if(d<18){
            cout<<"Before";
        }else if(d == 18){
            cout<<"Special";
        }else{
            cout<<"After";
        }
    }else{
        cout<<"After";
    }
}


