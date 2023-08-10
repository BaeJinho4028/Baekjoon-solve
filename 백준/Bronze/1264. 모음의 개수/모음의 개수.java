import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true){
            String s = br.readLine();
            if(s.equals("#")) break;

            s = s.toLowerCase();

            int ans =0;
            for(int i=0; i<s.length(); i++){
                char c = s.charAt(i);
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    ans++;
            }
            System.out.println(ans);
        }
    }
}
