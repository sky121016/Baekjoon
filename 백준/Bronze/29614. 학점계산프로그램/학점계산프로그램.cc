#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

using namespace std;

string s;
float total;
int cnt;

float getGrade(char c){
    cnt ++;
    if(c == 'A'){
        return 4;
    }else if(c == 'B'){
        return 3;
    }else if(c == 'C'){
        return 2;
    }else if(c == 'D'){
        return 1;
    }else if(c == 'F'){
        return 0;
    }else if(c == '+'){
        cnt--;
        return 0.5;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    for(int i = 0; i<s.length(); i++){
        total += getGrade(s[i]);
    }

    total /= cnt;
    cout << total;
}