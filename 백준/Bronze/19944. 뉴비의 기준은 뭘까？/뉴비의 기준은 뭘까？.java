import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        if(m <= 2) System.out.println("NEWBIE!");
        else if(m <= n)System.out.println("OLDBIE!");
        else System.out.println("TLE!");
    }
}

//자바로 좀 바꿔라
