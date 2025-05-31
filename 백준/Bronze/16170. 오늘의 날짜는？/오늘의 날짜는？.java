import java.time.Instant;
import java.util.Date;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Date date = new Date();
        Instant instant = date.toInstant();
        System.out.println(instant.toString().substring(0,4));
        System.out.println(instant.toString().substring(5,7));
        System.out.println(instant.toString().substring(8,10));
    }
}