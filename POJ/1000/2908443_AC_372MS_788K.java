import java.math.*;
import java.io.*;
import java.util.*;
import java.lang.*;
public class Main
{
	public static void main(String args[])throws Exception
	{
       	BufferedReader stdin = new BufferedReader( new InputStreamReader(System.in));
       	String line = stdin.readLine();
       	StringTokenizer st = new StringTokenizer(line);
		String sa = st.nextToken();
		String sb = st.nextToken();
		BigInteger a = new BigInteger(sa);
		BigInteger b = new BigInteger(sb);
		BigInteger s = a.add(b);
		System.out.println(s);
	}
}
