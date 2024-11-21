#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dsize;
int maxCnt;
bool visited[10];

void dfs(int remain, int cnt, vector<vector<int>> dungeons){   
    
    
    maxCnt = max(maxCnt, cnt);
    
    if(cnt == dsize){
        return;
    }
    
    for(int i = 0; i<dsize; i++){
        if(visited[i]){continue;}
        if(remain >= dungeons[i][0]){
            if(remain >= dungeons[i][1]){
                // cout<<dungeons[i][1]<<" "<<cnt<<"\n";
                visited[i] = true;
                dfs(remain-dungeons[i][1], cnt+1, dungeons);
                visited[i] = false;
            }
        }
    }
    
    if(remain == 0){
        return;
    }
 
}

int solution(int k, vector<vector<int>> dungeons) {
    dsize = dungeons.size();
    
    dfs(k, 0, dungeons);
    
    return maxCnt;
}