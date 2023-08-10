import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int s =0, t=0;

        while(st.hasMoreTokens()){
            s += Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        while(st.hasMoreTokens()){
            t += Integer.parseInt(st.nextToken());
        }

        System.out.println(Math.max(s, t));
    }
}
