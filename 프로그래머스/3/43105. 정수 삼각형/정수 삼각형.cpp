#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    dp[0][0] = triangle[0][0];
    cout<<triangle.size();
    for(int i = 1; i<triangle.size(); i++){
        dp[i][0] = dp[i-1][0] + triangle[i][0];
    }
    
    
    for(int i = 1; i<triangle.size(); i++){
        for(int j = 1; j<triangle[i].size(); j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
        }
    }
    
    
    return *max_element(dp[triangle.size()-1], dp[triangle.size()-1] + triangle.size());
    

}