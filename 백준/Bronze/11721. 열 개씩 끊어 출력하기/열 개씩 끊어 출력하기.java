import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        int n = s.length() /10;
        int idx =0;

        for(int i=0; i<n; i++){
            System.out.println(s.substring(idx, idx+10));
            idx+=10;
        }

        int tmp = s.length()%10;
        System.out.println(s.substring(s.length()-tmp));
    }
}