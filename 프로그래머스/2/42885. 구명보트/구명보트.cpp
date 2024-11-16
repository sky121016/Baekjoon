#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int cnt;
int l, r;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());

    l = 0;
    r = people.size()-1;

    while(l <= r){
        if(people[l] + people[r] <= limit){
            l++;
            r--;
            cnt++;
        }else{
            r--;    
            cnt++;
        }
        
        
    }



    return cnt;
}