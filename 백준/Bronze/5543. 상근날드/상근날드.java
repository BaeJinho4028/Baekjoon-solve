import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int a = 2005, b=2005;

        for(int i=0; i<3; i++){
            int x = Integer.parseInt(br.readLine());
            if(a > x)
                a = x;
        }

        for(int i=0; i<2; i++){
            int x = Integer.parseInt(br.readLine());
            if(b > x)
                b = x;
        }

        System.out.println(a+b - 50);

    }
}
