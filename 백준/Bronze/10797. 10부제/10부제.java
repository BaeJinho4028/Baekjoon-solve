import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int ans =0;
        for(int i =0; i<5; i++){
            int a= Integer.parseInt(st.nextToken());
            if(a==n) ans++;
        }

        System.out.println(ans);
    }
}
