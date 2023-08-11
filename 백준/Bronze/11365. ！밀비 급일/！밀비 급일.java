import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true){
            String s = br.readLine();
            if(s.equals("END")) break;

            int ans =0;
            for(int i=s.length() -1; i>=0; i--){
                System.out.print(s.charAt(i));
            }
            System.out.print('\n');
        }
    }
}
