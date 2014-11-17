//PKU Problem 1832 

import java.math.*;
import java.util.*;

class Main
{
	static int MAXSZ = 132;
	static int sour[] = new int[MAXSZ];
	static int dest[] = new int[MAXSZ];
	static BigInteger[] f120 = new BigInteger[MAXSZ];

	static BigInteger solve(int p)
	{
		if(p<=0)
			return BigInteger.ZERO;
		if(sour[p] == dest[p])
			return solve(p-1);
		BigInteger ret = set(p-1);
		//System.out.println("solve " + p + " ret = " + ret);
		return ret.add(BigInteger.ONE).add( solve(p-1) );
	}
	
	static BigInteger set(int p) //set XXXX to 1000
	{
		if(p<=0)
			return BigInteger.ZERO;
		int t = sour[p];
		sour[p]=1;
		if(p==1)
			return BigInteger.valueOf(1-t);
		if(t==1) //1XXX => 1000
			return clear(p-1);
		//0XXX => 0100 => 1100 => 1000
		BigInteger ret = set(p-1);
		//System.out.println("set " + p + " ret = " + ret);
		for(int q=p-1;q>0;q--)
			sour[q]=0;
		return ret.add(BigInteger.ONE).add( f120[p-1] );
	}
	
	static BigInteger clear(int p) //set XXXX to 0000
	{
		if(p<=0)
			return BigInteger.ZERO;
		int t = sour[p];
		sour[p]=0;
		if(p==1)
			return BigInteger.valueOf(t);
		if(t==0) return clear(p-1);
		BigInteger ret = set(p-1);
		//System.out.println("clear " + p + " ret = " + ret);
		for(int q=p-1;q>0;q--)
			sour[q]=0;
		return ret.add(BigInteger.ONE).add( f120[p-1] );
	}
	
	public static void main(String argv[])
	{
		f120[0] = BigInteger.ZERO;
		for(int i=1;i<MAXSZ;i++)
		{
			f120[i] = f120[i-1].add(f120[i-1]).add(BigInteger.ONE);
		}
		Scanner in = new Scanner(System.in);
		int ks = in.nextInt();
		while(ks-- > 0)
		{
			int n = in.nextInt();
			for(int i=n;i>0;i--) sour[i]=in.nextInt();
			for(int i=n;i>0;i--) dest[i]=in.nextInt();
			System.out.println( solve(n) );
		}
	}
}

/*
10
9
0 1 1 0 0 1 0 1 1
1 1 1 1 0 0 1 0 0

9
0 1 1 0 1 0 0 1 0
0 1 0 0 0 1 0 0 1

4
1 0 1 0
1 1 1 1


19
0 1 1 0 0 1 0 1 1 0 1 1 0 0 1 0 1 1 1
1 1 1 1 0 0 1 0 0 0 1 1 0 0 1 0 1 1 1

29
0 1 1 0 0 1 0 1 1 0 1 1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 1 1 0
1 1 1 1 0 0 1 0 0 0 1 1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 1 1 0

58
0 1 1 0 0 1 0 1 1 0 1 1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 1 1 0 0 1 1 0 0 1 0 1 1 0 1
1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 1 1 0
1 1 1 1 0 0 1 0 0 0 1 1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 1 1 0 0 1 1 0 0 1 0 1 1 0 1
1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 1 1 0

116
0 1 1 0 0 1 0 1 1 0 1 1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 1 1 0 0 1 1 0 0 1 0 1 1 0 1
1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 1 1 0 1 1 1 1 0 0 1 0 0 0 1 1 0 0 1 0 1 1 1 0 1 1
0 0 1 0 1 1 0 0 1 1 0 0 1 0 1 1 0 1 1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 1 1 0
0 1 1 0 0 1 0 1 1 0 1 1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 1 1 0 0 1 1 0 0 1 0 1 1 0 1
1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 1 1 0 1 1 1 1 0 1 0 0 0 1 1 0 0 1 0 0 1 1 1 0 1 1
0 0 1 0 1 1 0 0 1 1 0 0 1 0 1 1 0 1 1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 1 1 0

128
0 1 1 0 0 1 0 1 1 0 1 1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 1 1 0 0 1 1 0 0 1 0 1 1 0 1
1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 1 1 0 1 1 1 1 0 0 1 0 0 0 1 1 0 0 1 0 1 1 1 0 1 1
0 0 1 0 1 1 0 0 1 1 0 0 1 0 1 1 0 1 1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 1 1 0 0 1 1 0
0 1 1 0 0 1 1 0
0 1 1 0 0 1 0 1 1 0 1 1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 1 1 0 0 1 1 0 0 1 0 1 1 0 1
1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 1 1 0 1 1 1 1 0 0 1 0 0 0 1 1 0 0 1 0 1 1 1 0 1 1
0 0 1 0 1 1 0 0 1 1 0 0 1 0 1 1 0 1 1 0 0 1 0 1 1 1 0 1 1 0 0 1 0 1 1 0 0 1 1 0
0 1 1 0 0 1 1 0


186
85
2
190464
195035136
104708691336364032
4345269952970752
0

 */