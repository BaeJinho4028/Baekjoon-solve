import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b= Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        b += Integer.parseInt(st.nextToken());
        a += Integer.parseInt(st.nextToken());

        System.out.println(Math.min(a , b));
    }
}