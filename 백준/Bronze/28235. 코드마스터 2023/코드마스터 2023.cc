#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <map>
#include <set>

using namespace std;

string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    if(str == "SONGDO"){
        cout<<"HIGHSCHOOL";
    }else if(str == "CODE"){
        cout<<"MASTER";
    }else if(str == "2023"){
        cout<<"0611";
    }else if(str == "ALGORITHM"){
        cout<<"CONTEST";
    }
}
