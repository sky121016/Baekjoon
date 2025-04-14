import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        int d1, d2;
        Scanner s = new Scanner(System.in);

        d1 = s.nextInt();
        d2 = s.nextInt();

        System.out.println(2 * d1 + d2 * 2 * 3.141592);
    }
}