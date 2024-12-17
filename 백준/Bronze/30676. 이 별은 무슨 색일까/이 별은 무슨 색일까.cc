


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

int g;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> g;

    if(380 <= g && g < 425){
        cout<<"Violet";
    }else if(425 <= g && g < 450){
        cout<<"Indigo";
    }else if(450 <= g && g < 495){
        cout<<"Blue";
    }else if(495 <= g && g < 570){
        cout<<"Green";
    }else if(570 <= g && g < 590){
        cout<<"Yellow";
    }else if(590 <= g && g < 620){
        cout<<"Orange";
    }else if(620 <= g && g <= 780){
        cout<<"Red";
    }
}
