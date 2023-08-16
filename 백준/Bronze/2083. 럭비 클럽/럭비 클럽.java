import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            String a = st.nextToken();
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            if(a.equals("#") && b==0 && c==0) break;

            if(b > 17 || c >=80) System.out.println(a + " Senior");
            else System.out.println(a + " Junior");
        }
    }
}