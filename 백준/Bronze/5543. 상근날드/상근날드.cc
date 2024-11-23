#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>

using namespace std;

int burger[3];
int drink[2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i<3; i++){
        cin >> burger[i];
    }

    for(int i = 0; i<2; i++){
        cin >> drink[i];
    }

    cout << *min_element(burger, burger + 3) + *min_element(drink, drink + 2) - 50;
}
