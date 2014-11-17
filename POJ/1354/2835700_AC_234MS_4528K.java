import java.io.*;
import java.util.*;
import java.math.*;
public class Main{
	
	public static void main(String args[]) throws Exception {
		final int maxn = 210;
		BigInteger []dp = new BigInteger[maxn];
		dp[0] = new BigInteger("2");
		for(int i=1;i<maxn;i++)
			dp[i] = BigInteger.valueOf(i).multiply(dp[i-1]);
		Scanner cin=new Scanner(System.in);
		do{
			int a=cin.nextInt();
			if(a<0)break;
			System.out.println("N="+a+":\n"+dp[a-1]);
		}while(true);
	}
}