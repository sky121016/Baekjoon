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

int leg;
int chicken;
int t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t>0){

        cin>>leg>>chicken;

        int x = chicken * 2 - leg;
        cout << x << " " << chicken - x << "\n";

        t--;
    }


}
