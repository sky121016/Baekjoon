import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, m;
        n = scanner.nextInt();
        m = scanner.nextInt();

        int [] arr = new int[110];

        for(int i = 1; i<=n; i++){
            arr[i] = i;
        }

        int a, b;
        for(int i = 0; i<m; i++){
            a = scanner.nextInt();
            b = scanner.nextInt();

            while(a<b){
                int temp = arr[a];
                arr[a] = arr[b];
                arr[b] = temp;
                a++;
                b--;
            }
        }

        for(int i = 1; i<=n; i++){
            System.out.print(arr[i]+" ");
        }
    }
}