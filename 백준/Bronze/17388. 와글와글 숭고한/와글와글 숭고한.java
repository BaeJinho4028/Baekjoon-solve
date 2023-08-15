import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int s = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());

        if(s+k+h >=100) System.out.println("OK");
        else{
            int mn = Math.min(s,k);
            mn = Math.min(mn, h);

            if(mn == s) System.out.println("Soongsil");
            else if(mn == k) System.out.println("Korea");
            else if(mn == h) System.out.println("Hanyang");
        }
    }
}