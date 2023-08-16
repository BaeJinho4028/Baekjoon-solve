import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        for(int i=0; i<n; i++){
            int m = Integer.parseInt(br.readLine());
            for(int j=0; j<m; j++)
                System.out.print("=");
            System.out.println();
        }
    }
}