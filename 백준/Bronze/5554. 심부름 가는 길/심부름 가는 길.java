import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int sum =0;
        for(int i=0; i<4;i++) {
            int x= Integer.parseInt(br.readLine());
            sum += x;
        }

        System.out.println(sum/60);
        System.out.println(sum%60);
    }
}
