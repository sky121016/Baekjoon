import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static class Node{
        public int y;
        public int x;
        public char value;
        public boolean visited;
        public int fireDis;
        public int dis;

        public void setNode(int y, int x, char v){
            this.y = y;
            this.x = x;
            this.value = v;
            this.visited = false;
            fireDis = 0;
            dis = 0;
        }

        public void resetNode(){
            visited = false;
            fireDis = 0;
            dis = 0;
        }
    };

    

    static ArrayDeque<Node> fireq = new ArrayDeque<>();
    static ArrayDeque<Node> q = new ArrayDeque<>();
    static int [][]dir = {{-1, 0}, {0, 1}, {1, 0},{0, -1}};
    static int w;
    static int h;
    static Node [][] node;

    static boolean canFireVisit(int ny, int nx){
        return (ny >= 0 && ny < h && nx >= 0 && nx < w && node[ny][nx].value != '#' && node[ny][nx].fireDis == 0);
    }
    static boolean canVisit(int ny, int nx){
        return (ny >= 0 && ny < h && nx >= 0 && nx < w && node[ny][nx].value == '.' && !node[ny][nx].visited);
    }

    static void firebfs(){
        Node v;
        int ny, nx;

        while(!fireq.isEmpty()){
            v = fireq.poll();
            for(int i = 0; i<4; i++){
                ny = v.y + dir[i][0];
                nx = v.x + dir[i][1];

                if(canFireVisit(ny, nx)){
                    node[ny][nx].fireDis = v.fireDis + 1;
                    fireq.add(node[ny][nx]);
                }
            }
        }
    }

    static boolean isPossible(int ny, int nx){
        return(ny==0 || ny == h-1 || nx == 0 || nx == w-1);
    }

    static void bfs(){
        Node v;
        int ny, nx;
        
        v = q.peek();
        if(isPossible(v.y, v.x)){
            System.out.println(v.dis);
            return;
        }

        while(!q.isEmpty()){
            v = q.poll();
            for(int i = 0; i<4; i++){
                ny = v.y + dir[i][0];
                nx = v.x + dir[i][1];

                if(canVisit(ny, nx)&&(node[ny][nx].fireDis>v.dis+1||node[ny][nx].fireDis==0)){
                    node[ny][nx].dis = v.dis + 1;
                    node[ny][nx].visited = true;
                    q.add(node[ny][nx]);

                        
                    if(isPossible(ny, nx)){
                        System.out.println(node[ny][nx].dis);
                        return;
                    }
                }
            }
        }
        
        System.out.println("IMPOSSIBLE");
    }

    static void reset(){
        while(!q.isEmpty()){
            q.poll();
        }

        while(!fireq.isEmpty()){
            fireq.poll();
        }

        for(int i = 0; i<h; i++){
            for(int j = 0; j<w; j++){
                node[i][j].resetNode();
            }
        }
    }
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while(t>0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            w = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());
            node = new Node[h][w];

            for(int i = 0; i<h; i++){
                String input = br.readLine();
                for(int j = 0; j<w; j++){
                    node[i][j] = new Node();
                    char temp = input.charAt(j);
                    node[i][j].setNode(i, j, temp);

                    if(temp == '*'){
                        node[i][j].fireDis = 1;
                        fireq.add(node[i][j]);
                    }else if(temp == '@'){
                        node[i][j].dis = 1;
                        node[i][j].visited = true;
                        q.add(node[i][j]);

                    }
                    
                }
            }
            
            // spread fire
            firebfs();


            // move
            bfs();

            reset();

            t--;
        }

    }
}
