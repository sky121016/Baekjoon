import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s;

        for(int i = 0; i<n; i++){
            s = scanner.next();
            System.out.println(s.toLowerCase());
        }

    }
}