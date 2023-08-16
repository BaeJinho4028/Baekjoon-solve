import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int d = Integer.parseInt(br.readLine());
        int r = Integer.parseInt(br.readLine());

        double pi = 3.141592;

        System.out.println((double)(2*pi*r + 2*d));
    }
}