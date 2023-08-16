import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        while(n-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            s = s.toLowerCase();
            System.out.println(s);
        }

    }
}