import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int l = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());


        int tmp = l * p;
        st = new StringTokenizer(br.readLine());
        int[] arr= new int[5];
        for(int i =0; i<5; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            arr[i] -= tmp;
        }

        for(int i=0; i<5;i++){
            System.out.print(arr[i] + " ");
        }
    }
}
