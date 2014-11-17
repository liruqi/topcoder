import java.math.*;
import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String args[])throws Exception
	{
        Scanner cin=new Scanner(System.in);
       	while(cin.hasNext()){
            BigInteger a=cin.nextBigInteger();
            BigInteger b=cin.nextBigInteger();System.out.println(a.add(b));
    	}
    }

}
