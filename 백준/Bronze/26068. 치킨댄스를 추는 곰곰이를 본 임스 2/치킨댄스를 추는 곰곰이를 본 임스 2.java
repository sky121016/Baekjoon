import java.math.BigInteger;
import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int cnt = 0;

        while(n > 0){
            String s = scanner.next();
            String[] list = s.split("-");
            if(Integer.parseInt(list[1])<=90){
                cnt++;
            }
            n--;
        }

        System.out.println(cnt);
    }

}