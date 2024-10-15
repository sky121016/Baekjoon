// 17265
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n;
vector<string> s;

int g, b;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin.ignore();
    string temp;

    for(int i = 0; i<n; i++){
        // cin>>temp;
        // s.push_back(temp);
        getline(cin, temp);



        for(int j = 0; j<temp.length(); j++){
            if(temp[j] == 'g' || temp[j] == 'G'){
                g++;
            }else if(temp[j] == 'b' || temp[j] == 'B'){
                b++;
            }
            

        }
        
        if(g > b){
            cout << temp << " is GOOD\n";
        }else if(g < b){
            cout << temp << " is A BADDY\n";
        }else{
            cout << temp << " is NEUTRAL\n";
        }

        g = 0;
        b = 0;

    }
}

