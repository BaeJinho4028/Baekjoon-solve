import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = b / 100; //100
        int e = b-((b/10)*10); //1
        int f = (b - (c*100) - e) / 10; //10

        System.out.println(a*e);
        System.out.println(a*f);
        System.out.println(a*c);
        System.out.println(a*b);
    }
}