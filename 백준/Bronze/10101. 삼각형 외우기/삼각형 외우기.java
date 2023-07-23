import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int a = Integer.parseInt(br.readLine());
        int b = Integer.parseInt(br.readLine());
        int c = Integer.parseInt(br.readLine());

        if(a + b + c != 180)
            System.out.print("Error");
        else if(a == b && b == c)
            System.out.print("Equilateral");
        else if(a == b || b == c || a == c)
            System.out.print("Isosceles");
        else
            System.out.print("Scalene");
    }
}
