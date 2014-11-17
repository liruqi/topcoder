
import java.math.*;
import java.io.*;
import java.util.*;
import java.lang.*;

public class Main
{
	public static void main(String args[])throws Exception
	{
        BufferedReader stdin = new BufferedReader(
                new InputStreamReader(System.in));

        String line = stdin.readLine();
String[] sa = line.split(" ");
	BigInteger a = new BigInteger(sa[0]);
	BigInteger b = new BigInteger(sa[1]);
	BigInteger s = a.add(b);
	System.out.println(s);
	}
}
