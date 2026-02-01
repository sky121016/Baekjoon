import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());

        HashSet<String> set = new HashSet<>();

        for(int i = 0; i<n; i++){
            StringTokenizer input = new StringTokenizer(br.readLine());
            String name = input.nextToken();
            String log = input.nextToken();

            if(log.equals("enter")){
                set.add(name);
            }else if(log.equals("leave")){
                set.remove(name);
            }
        }

        ArrayList<String> list = new ArrayList<>();
        for(String name : set){
            list.add(name);
        }

        Collections.sort(list, Collections.reverseOrder());

        for(String name:list){
            System.out.println(name);
        }

    }
    
}