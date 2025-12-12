import java.util.*;
class Solution {
    class Node{
        int y, x;
        boolean visited;
        int dist;
        
        void setNode(int y, int x){
            this.y = y;
            this.x = x;
            dist = -1;
            visited= false;
        }
    }
    
    static int dir[][] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    public boolean canVisit(int ny, int nx, int n, int m){
        return ny>=0 && ny<n && nx>=0 && nx<m;
    }
    
    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;
        
        Node node[][] = new Node[101][101];
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                node[i][j] = new Node();
                node[i][j].setNode(i, j);
            }
        }
        
        
        Queue<Node> q = new LinkedList<>();
        
        Node v;
        
        node[0][0].visited = true;
        node[0][0].dist = 1;
        
        q.add(node[0][0]);
        
        while(!q.isEmpty()){
            v = q.element();
            q.remove();
            
            int ny, nx;
            
            if(v.y == n-1 && v.x == m-1){
                break;
            }
            
            for(int i = 0; i<4; i++){
                ny = v.y + dir[i][0];
                nx = v.x + dir[i][1];
                
                if(canVisit(ny, nx, n, m) && maps[ny][nx] == 1 && !node[ny][nx].visited){
                    node[ny][nx].visited = true;
                    node[ny][nx].dist = v.dist + 1;
                    q.add(node[ny][nx]);
                }
            }
        }
        
        int answer = node[n-1][m-1].dist;
        return answer;
    }
}