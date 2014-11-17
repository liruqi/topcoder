//poj 3199, calculate a^b
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
            //System.out.println(sa + " " + b);
            if(a.compareTo ( BigInteger.ZERO )==0) return;
		    System.out.println(a.pow(b));
        }
	}
}
