import java.util.*;
class Solution {
    boolean [] visited = new boolean [201];
    
    public void bfs(int V, int [][] computers){
        Queue<Integer> q = new LinkedList<>();
        visited[V] = true;
        q.add(V);
        
        int next;
        
        while(!q.isEmpty()){
            int v = q.poll();
            
            for(int i = 0; i<computers.length; i++){
                if(i != v && computers[v][i] == 1 && !visited[i]){
                    visited[i] = true;
                    q.add(i);
                }
            }
        }
        
    }
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                answer++;
                bfs(i, computers);
            }
        }
        
        return answer;
    }
}