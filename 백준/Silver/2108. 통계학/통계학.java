import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        // System.out.println((double)((int)(3.001*100)/100.00));
        // System.out.printf("%.2f\n",(double)(int)(3.1462*100)/100);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] nums = new int[n];
        int sum = 0;
        int [] count = new int[8001];


        for(int i = 0; i<n; i++){
            int temp = Integer.parseInt(br.readLine());
            nums[i] = temp;
            sum += temp;
            count[temp+4000]++;
        }

        Arrays.sort(nums);

        int maxIndex = 0;
        int maxValue = 0;
        int maxFreq = 0;

        for(int i = 0; i<count.length; i++){
            if(count[i] > maxValue){
                maxIndex = i;
                maxValue = count[i];
                maxFreq = i-4000;
            }
        }


        
        for(int i = maxIndex+1; i<count.length; i++){
            if(count[i] == maxValue){
                maxFreq = i-4000;
                break;
            }
        }


        
        int range = nums[nums.length - 1] - nums[0];

        System.out.println(Math.round((double)sum/n));
        System.out.println(nums[n/2]);
        System.out.println(maxFreq);
        System.out.println(range);


    }
    
}