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


int n;

string w[30] = {
    "ITMO",
    "SPbSU",
    "SPbSU",
    "ITMO",
    "ITMO",
    "SPbSU",
    "ITMO",
    "ITMO",
    "ITMO",
    "ITMO",
    "ITMO",
    "PetrSU, ITMO",
    "SPbSU",
    "SPbSU",
    "ITMO",
    "ITMO",
    "ITMO",
    "ITMO",
    "SPbSU",
    "ITMO",
    "ITMO",
    "ITMO",
    "ITMO",
    "SPbSU",
    "ITMO",
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    cout << w[n - 1995];
}

