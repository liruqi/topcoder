import java.io.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String args[]) throws Exception {
		int M = 200,i;
		BigInteger []dp = new BigInteger[M];
		dp[0] = new BigInteger("2");
		for(i=1;i<M;i++)
			dp[i] = BigInteger.valueOf(i).multiply(dp[i-1]);
		Scanner cin=new Scanner(System.in);
		while(true){
			i=cin.nextInt();
			if(i<0)break;
			System.out.println("N="+i+":\n"+dp[i-1]);
		}
	}
}