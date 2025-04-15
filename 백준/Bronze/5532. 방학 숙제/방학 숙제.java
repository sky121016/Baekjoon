import java.util.Scanner;
//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int l = s.nextInt();
        double a = s.nextInt();
        double b = s.nextInt();
        double c = s.nextInt();
        double d = s.nextInt();

        int math = (int)Math.ceil((b / d));
        int korean = (int)Math.ceil((a / c));

        int bigger = Math.max(math, korean);

        System.out.println(l - bigger);
    }

}
