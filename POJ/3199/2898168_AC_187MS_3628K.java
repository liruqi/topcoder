import java.math.*;
import java.io.*;
import java.util.*;
public class Main
{
	public static void main(String args[])throws Exception
	{
        Scanner cin=new Scanner(System.in);
       	while(true){
            BigInteger a=cin.nextBigInteger();
            int b=cin.nextInt();
            if(a.compareTo ( BigInteger.ZERO )==0) return; System.out.println(a.pow(b));
        }
	}
}
