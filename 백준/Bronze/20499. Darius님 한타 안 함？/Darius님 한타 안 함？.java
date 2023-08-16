import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        String[] arr = s.split("/");
        int k = Integer.parseInt(arr[0]);
        int d = Integer.parseInt(arr[1]);
        int a = Integer.parseInt(arr[2]);

        if((k+a)<d || d == 0) System.out.println("hasu");
        else System.out.println("gosu");
    }
}