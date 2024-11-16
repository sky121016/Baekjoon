// 3009
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

string s;
vector<int> num;
vector<char> op;

int sum;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int start = 0;

    cin >> s;

    for(int i = 0; i<s.length(); i++){
        if(s[i] == '-' || s[i] == '+'){
            string temp;
            temp = s.substr(start, i);
            start = i+1;
            num.push_back(stoi(temp));

            op.push_back(s[i]);
        }

    }

    string lastNum = s.substr(start, s.length());
    num.push_back(stoi(lastNum));


    bool flag = false;
    sum += num[0];

    for(int i = 0; i<op.size(); i++){
        if(op[i] == '-'){
            flag = true;
        }

        if(flag){
            sum -= num[i+1];
        }else{
            sum += num[i+1];
        }
    }

    cout << sum;
}
