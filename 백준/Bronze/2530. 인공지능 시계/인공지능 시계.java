import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        int d = Integer.parseInt(br.readLine());

        c += d;

        b += (c/60);
        c %= 60;

        a += (b/60);
        b %= 60;

        a %= 24;

        System.out.println(a + " " + b + " " + c);
    }
}
