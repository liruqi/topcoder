import java.util.*;
import java.math.*;
import java.io.*;
public class Main{
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        int T; T=cin.nextInt();
        while(T-- > 0){
            String sa = cin.next();
            String sb = cin.next();
            if(sa.charAt(0)=='+') sa = sa.substring(1);
            if(sb.charAt(0)=='+') sb = sb.substring(1);
            BigInteger a= new BigInteger(sa);
            BigInteger b= new BigInteger(sb);
            System.out.println(a.add(b));
        }
    }
}