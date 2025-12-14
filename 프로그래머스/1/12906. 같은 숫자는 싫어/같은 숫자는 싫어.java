import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
      
        Deque<Integer> dq = new ArrayDeque<>();
        
        dq.addFirst(arr[0]);
        
        for(int i = 1; i<arr.length; i++){
            int temp = dq.peekLast();
            if(temp != arr[i]){
                dq.addLast(arr[i]);
            }
        }
        
        int[] answer = new int[dq.size()];
        
        int size = dq.size();
        
        for(int i = 0; i<size; i++){
            answer[i] = dq.pollFirst();
        }

        return answer;
    }
}