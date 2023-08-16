import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


        int n = Integer.parseInt(br.readLine());

        if(n == 1010) System.out.println(20);
        else if(n/10 > 10) System.out.println((n/100) + (n%100));
        else System.out.println(n%10 + n/10);
    }
}