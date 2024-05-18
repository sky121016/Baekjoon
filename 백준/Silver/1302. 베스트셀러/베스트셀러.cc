// 1302
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>

using namespace std;

map<string, int> book;
int n;
int maxCnt;
string maxBook;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    string name;
    for(int i = 0; i<n; i++){
        cin >> name;
        if(book.find(name) != book.end()){
            book[name] += 1;
        }else{
            book.insert(make_pair(name, 1));
        }
    }

    for(auto i = book.begin(); i != book.end(); i++){
        if(maxCnt < i->second){
            maxCnt = i->second;
            maxBook = i->first;
        }
    }

    cout<<maxBook;

}
